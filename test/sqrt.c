#include <stdio.h>

#include <libdh/dh.h>
#include <libdh/dhmath.h>
#include <libdh/dhstr.h>

int main (int argc, char **argv){
	int i = 0;
	double x = 0;
	double y = 0;
	double z = 4;
	double d = 1;

	//printf("libdh %s\n", dh_version_str);

	if (argc > 1){
		x = sdecrep_to_fd_dh(argv[1]);
		printf("%.*f\n", 20, x);
	}
/*

*/
	while (i < 300) {
		z /= 2;
		d *= 2;
		y = y + (z/d);
		i++;
	}

	printf("%.*f\n", 20, y);
	return 0;
}
