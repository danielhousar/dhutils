/*****************************************************************************
 * file:	initmount/main.c
 ***************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/mount.h>
#include <mntent.h>
#include <errno.h>

/*

int lo_iface_up() {
	char *lo_addr = "127.0.0.1";
	char *lo_iface = "lo";
	return 0;
}

*/

int main () {

	umask(022);
	printf("Initmount 0.3 start\n");
	mkdir("/dev/pts", 0666);
	mkdir("/dev/shm", 0666);
	mount("none", "/proc", "proc", MS_RELATIME, "");
	mount("none", "/sys", "sysfs", MS_RELATIME, "");
	mount("none", "/tmp", "ramfs", 0, "");
	//perror("initmount");
	mount("devpts", "/dev/pts", "devpts", MS_RELATIME, "");
	mount("/dev/sda2", "/", "ext4", MS_REMOUNT|MS_RDONLY, "");
	mount("/dev/sda2", "/", "ext4", MS_REMOUNT, "");
	sethostname("pc-sempron", 10);

	//lo_iface_up();

	printf("Initmount done\n");

	return 0;
}

