#include <stdlib.h>
#include <unistd.h>
#include <syslog.h>

int main(int argc, char *argv[]) {
pid_t pid, sid;

/* Clone ourselves to make a child */
pid = fork();

/* If the pid is less than zero,
 *    something went wrong when forking */
if (pid < 0) {
    exit(EXIT_FAILURE);
}

/* If the pid we got back was greater
 *    than zero, then the clone was
 *       successful and we are the parent. */
if (pid > 0) {
    exit(EXIT_SUCCESS);
}

/* If execution reaches this point we are the child */
/* Set the umask to zero */
umask(0);

/* Open a connection to the syslog server */
openlog(argv[0],LOG_NOWAIT|LOG_PID,LOG_USER);

/* Sends a message to the syslog daemon */
syslog(LOG_NOTICE, "Successfully started daemon\n");

/* Try to create our own process group */
sid = setsid();
if (sid < 0) {
    syslog(LOG_ERR, "Could not create process group\n");
    exit(EXIT_FAILURE);
}

/* Change the current working directory */
if ((chdir("/")) < 0) {
    syslog(LOG_ERR, "Could not change working directory to /\n");
    exit(EXIT_FAILURE);
}

/* Close the standard file descriptors */
close(STDIN_FILENO);
close(STDOUT_FILENO);
close(STDERR_FILENO);

/* A useless payload to demonstrate */
while (1) {
    syslog(LOG_INFO, "My heart is beating...\n");
    sleep(15);
}

/* this is optional and only needs to be done when your daemon exits */
closelog();

}

