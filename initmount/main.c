/*****************************************************************************
 * file:	initmount/main.c
 ***************************************************************************** */
#include "config.h"

#include <unistd.h>
#include <ctype.h>
#include <stdio.h>
#include <errno.h>
#include <fcntl.h>

#include <sys/types.h>
#include <sys/ioctl.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/mount.h>

#include <mntent.h>

#include "initmount.h"

int main (int argc, char **argv) {
	int result = 0;

/* init */

	umask(022);

	result += mount ("none", "/proc", "proc", MS_RELATIME, "");
	result += mount ("none", "/sys", "sysfs", MS_RELATIME, "");
	result += mount ("none", "/tmp", "ramfs", MS_RELATIME, "");

	printf("result %i\n", result);

/* end */
	return result;
}

