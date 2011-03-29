#include <stdio.h>
#include "../include/danhmath.h"
#include "../include/danh.h"
#include "../include/types.h"

int main (int argc, char **argv){
	char** ss = ssplit_dh("slovoa-slovob-slovoc", '-');
	puts("ss set, now should be printf");
	printf("%s\n", ss[0]);
	return 0;
}

