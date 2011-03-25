#include <stdio.h>
#include "../include/danhmath.h"
#include "../include/danh.h"
#include "../include/types.h"

int main (int argc, char **argv){
	double x;
	scanf("%lG", &x);
	double root = misc_sqrt_double_dh(x);
	printf("%lf\n", root);
}
