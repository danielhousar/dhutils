#include <stdio.h>
#include "../include/danhmath.h"
#include "../include/danh.h"
#include "../include/types.h"

int main (int argc, char **argv){
	float x;
	scanf("%f", &x);
	float root = misc_sqrt_dh(x);
	printf("%f\n", root);
}
