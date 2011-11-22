#include <stdio.h>
#include <libdh/dh.h>
#include <libdh/dhstr.h>
#include <libdh/dhmisc.h>

int main () {
	printf("li = %li\n", shexrep_to_li_dh("0xaf"));
	printf("%x\n", 175);
	printf("fd = %f\n", sdecrep_to_fd_dh("2.0"));
	printf("ui = %u\n", sbinrep_to_ui_dh("00011000"));
	printf("bin 20 = %s\n", ui_to_binrep_dh(20));
	return 0;
}
