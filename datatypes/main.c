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
	printf("size of int: %i\n", sizeof(int));
	printf("size of long: %i\n", sizeof(long));
	printf("size of float: %i\n", sizeof(float));
	printf("size of double: %i\n", sizeof(double));
	printf("size of long double: %i\n", sizeof(long double));
	printf("size of size_t: %i\n", sizeof(size_t));
	return 0;
}
