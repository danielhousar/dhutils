#include <stdio.h>
#include <math.h>
#include <complex.h>

#include <libdh/dh.h>
#include <libdh/dhmath.h>
#include <libdh/dhstr.h>

//typedef double[2] complex

int main(int argc, char **argv) {
	_Complex double a = 2.0+1.0fi;

	printf("a = %f + %fi\n", __real__ a, __imag__ a);
	printf("a = %g\n", a);
	//int i = 0;

	//while (argc > 1 && i) {

	//}
	return 0;
}
