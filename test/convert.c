#include <stdio.h>
#include "../include/dh.h"
#include "../include/types.h"

int main () {
	printf("li = %i\n", shexrep_to_li_dh("1xaf"));
	printf("fd = %f\n", sdecrep_to_fd_dh("2.0"));
	printf("ui = %u\n", sbinrep_to_ui_dh("00011000"));
	print_ui_to_sbinrep_dh(20);
	return 0;
}
