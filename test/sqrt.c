#include <stdio.h>
#include "../include/dhmath.h"
#include "../include/dh.h"
#include "../include/dhstr.h"

int main (int argc, char **argv){
	long double x;
	printf("libdh %s\n", dh_version_str);
	if (argc > 1){
		x = sdecrep_to_fld_dh(argv[1]);
		printf("%.*Lf\n", 20, sqrt_fld_dh(x));
	}
	return 0;
}
