/***************************************************************
 * file:	utils/dhmount.c
 *
 * Much simple mount utility. Used only for case, when you are
 * definitely sure, that both mountpoint and device exist
 * and are accessible. Also you have to know filesystem type.
 *************************************************************** */
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/mount.h>
#include <mntent.h>
#include <errno.h>

int main (int argc, char **argv) {
	switch (argc) {
	case 4:
		/* mount(dev,dir,fs,mflags,data) */
		mount( argv[1], argv[2], argv[3], MS_RELATIME, "");
		perror("dhmount");
		break;
	case 3:
		umount(argv[1]);
		perror("dhmount");
		break;
	default:
		printf("no action\n");
	}


	return 0;
}
