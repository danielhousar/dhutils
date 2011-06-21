/*****************************************************************************
 * file:	initmount/main.c
 ***************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/mount.h>
#include <mntent.h>

#ifndef MS_RELATIME
#define MS_RELATIME 0x200000
#endif

int main () {

	umask(022);

	mount("none", "/proc", "proc", MS_RELATIME, "");
	mount("none", "/sys", "sysfs", MS_RELATIME, "");
	mount("none", "/tmp", "ramfs", MS_RELATIME, "");
	mount("devpts", "/dev/pts", "devpts", MS_RELATIME, "");
	mount("/dev/sda4", "/", "ext4", MS_REMOUNT|MS_RDONLY, "");
	mount("/dev/sda4", "/", "ext4", MS_REMOUNT, "");
	//mount("/dev/sda4", "/", "ext4", MS_RELATIME, "");
	sethostname("pc-athlon64", 11);

	return 0;
}

