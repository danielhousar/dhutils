#include <stdio.h>
#include "../include/dhmath.h"
#include "../include/dh.h"
#include "../include/types.h"

int main (int argc, char **argv){
	double x;
	printf("libdh %s\n", dh_version_string);
	if (argc > 1){
		x = sdecrep_to_fd_dh(argv[1]);
		double root = sqrt_fd_dh(x);
		printf("%.*f\n", 10, sqrt_fd_dh(x));
	}
	return 0;
}
