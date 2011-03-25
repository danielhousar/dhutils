#include <stdio.h>
#include "../include/danhmath.h"
#include "../include/danh.h"
#include "../include/types.h"

int main (int argc, char **argv){
	double x;
	printf("libdanh: %s\n", libdanh_version);
	if (argc > 1){
		x = str_to_double_dh(argv[1]);
	}
	else scanf("%lG", &x);
	double root = misc_sqrt_double_dh(x);
	printf("%.*f\n", 10, root);
}
