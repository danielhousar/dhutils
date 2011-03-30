#include <stdio.h>
#include "../include/danh.h"
#include "../include/types.h"

int main () {
	long testvar = shexrep_to_li_dh("0xFf");
	printf("testvar = %i\n", testvar);
	return 0;
}
