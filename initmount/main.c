/*****************************************************************************
 * file:	initmount/main.c
 ***************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/mount.h>
#include <mntent.h>

int main () {

	umask(022);

	mount("none", "/proc", "proc", MS_RELATIME, "");
	mount("none", "/sys", "sysfs", MS_RELATIME, "");
	mount("none", "/tmp", "ramfs", MS_RELATIME, "");
	mount("devpts", "/dev/pts", "devpts", MS_RELATIME, "");
	mount("/dev/sda2", "/", "ext4", MS_REMOUNT|MS_RDONLY, "");
	mount("/dev/sda2", "/", "ext4", MS_REMOUNT, "");
	sethostname("pc-sempron", 10);

	return 0;
}

