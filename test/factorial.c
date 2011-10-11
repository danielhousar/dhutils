#include <stdio.h>
#include <math.h>
#include "../include/dh.h"
#include "../include/dhmath.h"
#include "../include/dhstr.h"

int main(int argc, char **argv) {
	long double x = 0.0;
	long double a = 0.0;

	if (argc > 1) {
		a = sdecrep_to_fld_dh(argv[1]);
	}

	x = factorial_dh(a);
	printf("%Lf\n", x);

	return 0;
}
