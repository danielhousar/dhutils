#include <stdio.h>
#include "../include/dh.h"
#include "../include/dhmath.h"
#include "../include/dhstr.h"

int main(int argc, char **argv){
	printf("%.*Lf\n", 20, sin_dh(PI_dh / 3.0));
	printf("%.*Lf\n", 20, cos_dh(PI_dh / 3.0));
	return 0;
}
