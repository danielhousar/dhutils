#include <stdio.h>

#include <libdh/dh.h>
#include <libdh/dhmath.h>
#include <libdh/dhstr.h>

int main(int argc, char **argv){
	long double z;
	long long y;
	if (argc > 2) {
		printf("%s\n", argv[0]);
		z = sdecrep_to_fld_dh(argv[1]);
		y = snumrep_to_i_dh(argv[2]);
		printf("%Lf\n", pow_dh(z, y));
	}
	return 0;
}
