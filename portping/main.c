/***************************************************************
 * file:	portping/main.c
 *
 * License:	Creative Commons Attribution 3.0
 *
 * Author:	Matthew Fernandez (matthew.fernandez@gmail.com)
 *
 ***************************************************************/


#include <netinet/in.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>

#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/time.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include "../include/dh.h"
#include "../include/dhstr.h"

#define SOCKET_TIMEOUT 10 // seconds

const char* pp_version_string = "0.7 2011-05-06";

/* Return 1 if the socket becomes ready for reading or writing during the
 * defined timeout value.
 */
int pp_ready(int socket) {
	fd_set readfds, writefds;
	struct timeval timeout = { .tv_sec = SOCKET_TIMEOUT, .tv_usec = 0 };

	FD_ZERO(&readfds);
	FD_ZERO(&writefds);
	FD_SET(socket, &readfds);
	FD_SET(socket, &writefds);
	return select(socket + 1, &readfds, &writefds, (fd_set*)0, &timeout);
}

int main(int argc, char **argv) {
	char loop = 0;
	char udp = 0;
	char prt_ver = 0;
	int sockfd;
	int portno = 0;
	struct sockaddr_in serv_addr;
	struct hostent* server;
	struct timeval tick;
	struct timeval tock;
	int result;
	long elapsed;
	int protocol;
	int i = 0;

/* init */
	while (i < argc) {
		// controls each command-line arg
		if (!strcmp_dh(argv[i], "-t")) { loop = 1; }
		if (s_is_num_dh(argv[i]) == 1) { portno = atoi(argv[i]); }
		if (!strcmp_dh(argv[i], "udp")) { udp = 1; }
		if (!strcmp_dh(argv[i], "-v")) { prt_ver = 1; }
		i++;
	}

	if (prt_ver == 1) {
		printf("portping %s\n", pp_version_string);
		return 0;
	}

	if (argc < 3) {
		printf("Usage: %s [-v] | hostname port [-t] [udp]\n", argv[0]);
		puts(" ");
		printf("\t-v \tPrints out version info\n");
		printf("\t-t \tLoop ping given host and port\n");
		printf("\tudp \tSwitch to UDP (TCP is by default)\n");
        return 0;
    }

	if (!portno) {
		fprintf(stderr, "Invalid port number.\n");
		return 0;
	}

	if (udp == 1)
		protocol = SOCK_DGRAM;
	else
		protocol = SOCK_STREAM;

/* core */
	do {
		sockfd = socket(AF_INET, protocol, 0);

		if (sockfd < 0) {
			perror("Error opening socket");
			return 1;
		}

		/* Set the socket to non-blocking. */
		result = fcntl(sockfd, F_SETFL, fcntl(sockfd, F_GETFL, 0) | O_NONBLOCK);

		if (result < 0) {
			perror("Error setting socket to non-blocking");
			return 1;
        }


		/* Lookup the provided host. */
		server = gethostbyname(argv[1]);
		if (!server) {
            perror("DNS lookup failed");
            return 1;
        }

        gettimeofday(&tick, 0);
        memset(&serv_addr, 0, sizeof(serv_addr));
        serv_addr.sin_family = AF_INET;
        memmove(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);
		serv_addr.sin_port = htons(portno);

        if (protocol == SOCK_STREAM) { /* TCP */
            connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));

            /* The socket will only become ready if the connection succeeds. */
            result = pp_ready(sockfd) - 1;
        } else { /* UDP */
            connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));

            /* Sending to a closed UDP socket generates an error condition that
             * triggers on the next syscall with the socket. The error code
             * after this allows us to determine the status of the socket. This
             * method can generate false positives.
             */
            sendto(sockfd, 0, 0, 0, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
            result = sendto(sockfd, 0, 0, 0, (struct sockaddr *)&serv_addr, sizeof(serv_addr));

			if (errno == ECONNREFUSED) { result = 1; }
        }

        gettimeofday(&tock, 0);
        elapsed = (tock.tv_sec - tick.tv_sec) * 1000 + (tock.tv_usec - tick.tv_usec) / 1000;

        switch(result) {
            case -1:
                printf("No response from");
                break;
            case 0:
                printf("Response from");
                break;
            default:
                printf("Connection blocked by");
                break;
        }
        printf(" %s:%s (time=%lums)\n", argv[1], argv[2], elapsed);

        close(sockfd);
        sleep(1);

    } while (loop == 1);

    return 0;
}

