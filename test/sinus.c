#include <stdio.h>
#include "../include/dh.h"
#include "../include/dhmath.h"
#include "../include/types.h"

int main(int argc, char *argv){
	double angle = PI_dh / 6;
	double retval = 0.0;
	int i;
	while (i < 100) {
		retval = (pow_dh(-1, n) * pow_dh(x, (2 * i) + 1)) / factoriald_dh((2 * i) + 1);
		i++;
	}
	printf("%f\n", retval);
	return 0;
}