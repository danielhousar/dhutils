#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <syslog.h>
#include <unistd.h>

#define DEFAULT_INTERVAL 20
#define DEFAULT_LOGFLAG 0

/* main */
int
main(int argc, char **argv)
{
	static int      ch, interval, logflag;
	pid_t   pid, sid;

	interval = DEFAULT_INTERVAL;
	logflag  = DEFAULT_LOGFLAG;


	while ((ch = getopt(argc, argv, "lp:")) != -1) {
		switch (ch) {
			case 'l':
				logflag = 1;
				break;
			case 'p':
				interval = atoi(optarg);
				break;
               }
		}

        pid = fork();

        if (pid < 0) {
                exit(EXIT_FAILURE);
        } else if (pid > 0) {
                exit(EXIT_SUCCESS);
        }

        umask(0);

        sid = setsid();

        if (sid < 0) {
                exit(EXIT_FAILURE);
        }

        if ((chdir("/")) < 0) {
                exit(EXIT_FAILURE);
        }

        if (logflag == 1)
                syslog (LOG_NOTICE, " started by User %d", getuid ());

        while (1) {
                sleep(interval);
                printf("tic\n");
        }

        exit(EXIT_SUCCESS);
}
