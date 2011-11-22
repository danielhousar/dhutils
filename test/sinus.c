#include <stdio.h>

#include <libdh/dh.h>
#include <libdh/dhmath.h>

int main(int argc, char **argv){
	printf("%.*Lf\n", 20, sin_dh(PI_dh / 3.0));
	printf("%.*Lf\n", 20, cos_dh(PI_dh / 3.0));
	return 0;
}
