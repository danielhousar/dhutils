#include <stdio.h>
#include "../include/danhmath.h"
#include "../include/danh.h"
#include "../include/types.h"

int main (int argc, char **argv){
	double x;
	printf("libdanh: %s\n", dh_version_string);
	if (argc > 1){
		x = s_to_fd_dh(argv[1]);
	}
	else scanf("%lG", &x);
	double root = sqrt_fd_dh(x);
	printf("%.*f\n", 10, root);
}
