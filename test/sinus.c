#include <stdio.h>
#include "../include/dh.h"
#include "../include/dhmath.h"
#include "../include/types.h"

int main(int argc, char **argv){
	double angle = PI_dh / 6.0;
	double retval = angle;
	double n = 1.0;
	double exp;

	printf("PI = %f\n", PI_dh / 6.0);
	printf("2^3 = %f\n", pow_dh(2, 3));
	printf("20! = %f\n", factorial_dh(20));

	while (n < 20.0) {
		exp = (2 * n) + 1;
		retval += ((pow_dh(-1, n) * pow_dh(angle, exp)) / factorial_dh(exp));
		printf("%f\n", retval);
		n += 1.0;
	}
	printf("%f\n", retval);
	return 0;
}
