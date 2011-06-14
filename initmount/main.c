/*****************************************************************************
 * file:	initmount/main.c
 ***************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <fcntl.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mount.h>

#include <mntent.h>

#ifndef MS_RELATIME
#define MS_RELATIME 0x200000
#endif

int main (int argc, char **argv) {
	int result = 0;

	umask(022);

	result += mount ("none", "/proc", "proc", MS_RELATIME, "");
	result += mount ("none", "/sys", "sysfs", MS_RELATIME, "");
	result += mount ("none", "/tmp", "ramfs", MS_RELATIME, "");
	result += mount ("devpts", "/dev/pts", "devpts", MS_RELATIME, "");

	printf("initmount result %i\n", result);

	return result;
}

