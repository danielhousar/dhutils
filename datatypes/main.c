/***************************************************************
 * file:	datatypes/main.c
 ***************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//#include "../include/danhmath.h"
//#include "../include/danh.h"
//#include "../include/types.h"

int main (int argc, char **argv){
	puts("datatypes 0.3 2011-03-29");
	puts(" ");
	puts("----- ENVIRONMENT -----");
	puts(" ");
	puts("sizeof()");
	printf("short: %i\n", sizeof(short));
	printf("int: %i\n", sizeof(int));
	printf("long: %i\n", sizeof(long));
	printf("long long: %i\n", sizeof(long long));
	printf("float: %i\n", sizeof(float));
	printf("double: %i\n", sizeof(double));
	printf("long double: %i\n", sizeof(long double));
	printf("size_t: %i\n", sizeof(size_t));
	puts(" ");
	puts("-----------------------");
	
#ifdef WIN32
	puts("WIN32 defined");
#endif
#ifdef _WIN32
	puts("_WIN32 defined");
#endif
	puts(" ");
	return 0;
}
