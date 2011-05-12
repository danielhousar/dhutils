/******************************************************
 * file:	libdh/math.c
 ****************************************************** */

#include "../include/dhmath.h"

const double PI_dh = 3.14159265358979323846;
const double E_dh = 2.7182818284590452354;

double factorial_dh(double a){
	double retval = 1.0;
	double i = 1.0;
	if (a <= 0 || a > 170) { retval = 0.0; }
	else {
		while (i <= a){
			retval *= i;
			i++;
		}
	}
	return retval;
}

float sqrtf_dh(float a){
	int i = 0;
	float var1 = a;
	float var2 = 0.0;
	float var3 = 0.0;
	while ((var3 * var3) != a && i < 300) {
		var3 = (var1 + var2) / 2.0;
		if ((var3 * var3) > a) { var1 = var3; }
		else { var2 = var3; }
		i++;
	}
	return var3;
}

double sqrtd_dh(double a){
	int i = 0;
	double var1 = a;
	double var2 = 0.0;
	double var3 = 0.0;
	while ((var3 * var3) != a && i < 300) {
		var3 = (var1 + var2) / 2.0;
		if ((var3 * var3) > a) { var1 = var3; }
		else { var2 = var3; }
		i++;
	}
	return var3;
}

double mad_d_dh(double a){
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

double quadequi_dh (double a, double b, double c, int x){
	double d, discr;
	double x1, x2;
	discr = (b * b) - (4.0 * a * c);

	if (discr < 0.0) {
		x1 = 0.0;
		x2 = 0.0;
	}

	else {
		d = sqrtd_dh(discr);
		x1 = (-b - d) / (2.0 * a);
		x2 = (-b + d) / (2.0 * a);
	}

	if (x == 2)
		return x2;
	else return x1;
}

double sin_deg_dh(double a){
	double angle = PI_dh * (a / 180.0);
	double retval = angle;
	double n = 1.0;
	double exp;

	while (n < 60.0) {
		exp = (2 * n) + 1;
		retval += ((pow_dh(-1, n) * pow_dh(angle, exp)) / factorial_dh(exp));
		n += 1.0;
	}
	return retval;
}

double sin_rad_dh(double a){
	double retval = a;
	double n = 1.0;
	double exp;

	while (n < 60.0) {
		exp = (2 * n) + 1;
		retval += ((pow_dh(-1, n) * pow_dh(a, exp)) / factorial_dh(exp));
		n += 1.0;
	}
	return retval;
}

double radtodeg_dh(double a){
	return ((a / PI_dh) * 180.0);
}

double degtorad_dh(double a){
	return (PI_dh * (a / 180.0));
}

double degtorad_spec_dh(double a){
	return (a / 180.0);
}

double pow_dh(double a, double exp) {
	double retval = a;
	long i = 1;

	if (exp < 0){
		exp *= -1;
		while (i < exp) {
			retval *= a;
			i++;
		}
		retval = 1.0 / retval;
	}
	else {
		while (i < exp) {
			retval *= a;
			i++;
		}
	}

	return retval;
}

