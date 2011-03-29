/******************************************************
 * file:	libdanh/math.c
 ****************************************************** */

#include "../include/danhmath.h"

double factorial_fd_dh(double a){
	double retval = 1;
	if (a <= 0 || a > 170) { return 0; }
	else {
		double i = 1;
		while (i <= a){
			retval *= i;
			i++;
		}
	return retval;
	}
}

float sqrt_f_dh(float a){
	int i = 0;
	float var1 = a;
	float var2 = 0.0;
	float var3;
	while ((var3 * var3) > a || (var3 * var3) < a) {
		var3 = (var1 + var2) / 2.0;
		if ((var3 * var3) > a) { var1 = var3; }
		else { var2 = var3; }
		i++;
	}
	return var3;
}

double sqrt_fd_dh(double a){
	int i = 0;
	double var1 = a;
	double var2 = 0.0;
	double var3;
	while ((var3 * var3) != a && i < 300) {
		var3 = (var1 + var2) / 2.0;
		if ((var3 * var3) > a) { var1 = var3; }
		else { var2 = var3; }
		i++;
		//printf("%.*f\t %d\n", 20, var3, i);
	}
	return var3;
}

double mad_fd_dh(double a){
	double retval = a;
	double helper1 = a;
	double helper2 = 0;
	int counter = 0;
	while (counter < 10){
		retval = (helper1 + helper2) / 2.00;
		helper2 = retval;
		helper1 = (helper1 + helper2) / 2.00;
		retval = helper1;
		counter++;
	}
	return retval;
}

double quadequi_fd_dh (double a, double b, double c, int x){
	double d, discr;
	double x1, x2;
	discr = (b * b) - (4.0 * a * c);

	if (discr < 0.0) {
		//double div;
		//div = 2.0 * a;
		//discr *= -1.0;
		//d = sqrt_double_dh(discr);
		//d /= div;
		//b = b * -1.0 / div;
		x1 = 0.0;
		x2 = 0.0;
	}

	else {
		d = sqrt_fd_dh(discr);
		x1 = (-b - d) / (2.0 * a);
		x2 = (-b + d) / (2.0 * a);
	}

	if (x == 2)
		return x2;
	else return x1;
}

