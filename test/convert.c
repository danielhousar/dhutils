#include <stdio.h>
#include "../include/danh.h"
#include "../include/types.h"

int main () {
	long l = shexrep_to_li_dh("1xaf");
	double d = sdecrep_to_fd_dh("2.0");
	printf("l = %i\n", l);
	printf("d = %f\n", d);
	return 0;
}
