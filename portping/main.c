/***************************************************************
 * file:	portping/main.c
 *
 * License:	Creative Commons Attribution 3.0
 *
 * Author:	Matthew Fernandez (matthew.fernandez@gmail.com)
 *
 ***************************************************************/

#ifdef _WIN32
    /* You'll need to pass the switch -lws2_32 to GCC for the Winsock components to compile. */
    #include <winsock2.h>
    #include <ws2tcpip.h>
    #include <windows.h>
#else
    #include <netinet/in.h>
    #include <netdb.h>
	#include <sys/types.h>
    #include <sys/socket.h>
#endif

#include <unistd.h>
#include <stdio.h>
#include <sys/time.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include "../include/danh.h"
#include "../include/types.h"

#define SOCKET_TIMEOUT 10 // seconds

const char* pp_version_string = "0.5 2011-05-04";

static inline int init(void) {
#ifdef _WIN32
    WORD wVersionRequested;
    WSADATA wsaData;

    /* Initialise Winsock. */
    wVersionRequested = MAKEWORD(1, 0);
    return WSAStartup(wVersionRequested, &wsaData);
#else
    return 0;
#endif
}

static inline void cleanup(void) {
#ifdef _WIN32
    /* Unload Winsock resources. */
    WSACleanup();
#endif
}

/* Return 1 if the socket becomes ready for reading or writing during the
 * defined timeout value.
 */
int ready(int socket) {
    fd_set readfds, writefds;
    struct timeval timeout = { .tv_sec = SOCKET_TIMEOUT, .tv_usec = 0 };

    FD_ZERO(&readfds);
    FD_ZERO(&writefds);
    FD_SET(socket, &readfds);
    FD_SET(socket, &writefds);
    return select(socket + 1, &readfds, &writefds, (fd_set*)0, &timeout);
}

int main(int argc, char **argv)
{
	int loop = 0;
	int udp = 0;
	int prt_ver = 0;
    int sockfd, portno;
    struct sockaddr_in serv_addr;
    struct hostent* server;
    struct timeval tick;
    struct timeval tock;
    int result;
    long elapsed;
    int protocol;
    int i = 0;
	long imode = 1; //non-blocking mode, set to 0 for blocking mode

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
		fprintf(stderr,"Usage: portping [-v] | hostname port [-t] [udp]\n");
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

    if (init()) {
        perror("Error during initialisation");
        return 1;
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
            cleanup();
            return 1;
        }

        /* Set the socket to non-blocking. */
#ifdef _WIN32
		result = ioctlsocket(sockfd, FIONBIO, &imode);
		//printf("result = %i\n", result);
#else
        result = fcntl(sockfd, F_SETFL, fcntl(sockfd, F_GETFL, 0) | O_NONBLOCK);
#endif
        if (result < 0) {
            perror("Error setting socket to non-blocking");
            cleanup();
            return 1;
        }


        /* Lookup the provided host. */
        server = gethostbyname(argv[1]);
        if (!server) {
            perror("DNS lookup failed");
            cleanup();
            return 1;
        }

        gettimeofday(&tick, 0);
        memset(&serv_addr, 0, sizeof(serv_addr));
        serv_addr.sin_family = AF_INET;
        memmove(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);
        serv_addr.sin_port = htons(portno);

        if (protocol == SOCK_STREAM) { /* TCP */
            connect(sockfd, &serv_addr, sizeof(serv_addr));

            /* The socket will only become ready if the connection succeeds. */
            result = ready(sockfd) - 1;
        } else { /* UDP */
            connect(sockfd, &serv_addr, sizeof(serv_addr));

            /* Sending to a closed UDP socket generates an error condition that
             * triggers on the next syscall with the socket. The error code
             * after this allows us to determine the status of the socket. This
             * method can generate false positives.
             */
            sendto(sockfd, 0, 0, 0, &serv_addr, sizeof(serv_addr));
            result = sendto(sockfd, 0, 0, 0, &serv_addr, sizeof(serv_addr));
#ifdef _WIN32
			if (errno == WSAECONNREFUSED) { result = 1; } // This will happen on ICMP error indicating a blocked port.
#else
			if (errno == ECONNREFUSED) { result = 1; }
#endif
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

#ifdef _WIN32
        closesocket(sockfd);
        Sleep(1);
#else
        close(sockfd);
        sleep(1);
#endif

    } while (loop == 1);

    cleanup();
    return 0;
}

