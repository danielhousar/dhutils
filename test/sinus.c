#include <stdio.h>
#include "../include/dh.h"
#include "../include/dhmath.h"
#include "../include/types.h"

int main(int argc, char **argv){
	printf("%f\n", sin_deg_dh(30.0));
	printf("%f\n", sin_rad_dh(PI_dh / 3.0));
	return 0;
}
