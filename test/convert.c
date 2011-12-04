#include <stdio.h>
#include <libdh/dh.h>
#include <libdh/dhstr.h>
#include <libdh/dhmisc.h>

int main () {
	char pole[64];
	//sprintf(pole, "%f", 2.025);
	ui2bins_t_dh(pole, 20);
	printf("li = %li\n", shexrep_to_li_dh("0xaf"));
	printf("%x\n", 175);
	printf("fd = %f\n", sdecrep_to_fd_dh("2.0"));
	printf("ul = %lu\n", sbinrep_to_ul_dh("00011000"));
	printf("bin 20 = %s\n", pole);
	//printf("bin 20 = %s\n", ui_to_binrep_dh(pole,20));
	return 0;
}
