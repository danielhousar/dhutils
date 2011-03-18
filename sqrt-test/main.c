#include <stdio.h>
#include "../include/danhmath.h"
#include "../include/danh.h"
#include "../include/types.h"

int main (int argc, char **argv){
	//float x;
	double y;
	//scanf("%f", &x);
	scanf("%lG", &y);
	//float root = misc_sqrt_dh(x);
	double root2 = misc_sqrt_double_dh(y);
	printf("%f\n", root2);
}
