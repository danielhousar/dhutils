#include <stdio.h>
#include "../include/dh.h"
#include "../include/dhstr.h"
#include "../include/dhmisc.h"

int main () {
	printf("li = %li\n", shexrep_to_li_dh("1xaf"));
	printf("fd = %f\n", sdecrep_to_fd_dh("2.0"));
	printf("ui = %u\n", sbinrep_to_ui_dh("00011000"));
	printf("bin 20 = %s\n", ui_to_binrep_dh(20));
	return 0;
}
