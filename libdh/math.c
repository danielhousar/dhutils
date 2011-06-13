/******************************************************
 * file:	libdh/math.c
 ****************************************************** */

#include "../include/dhmath.h"

long double factorial_dh(long double a){
	long double retval = 1.0;
	long double i = 1.0;
	if (a <= 0 || a > 170) { retval = 0.0; }
	else {
		while (i <= a){
			retval *= i;
			i += 1.0;
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

double sqrt_dh(double a){
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

long double sqrt_fld_dh(long double a){
	int i = 0;
	long double var1 = a;
	long double var2 = 0.0;
	long double var3 = 0.0;
	while (i < 1000) {
		var3 = (var1 + var2) / 2.0;
		if ((var3 * var3) > a) { var1 = var3; }
		else { var2 = var3; }
		i++;
	}
	return var3;
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
		d = sqrt_dh(discr);
		x1 = (-b - d) / (2.0 * a);
		x2 = (-b + d) / (2.0 * a);
	}

	if (x == 2)
		return x2;
	else return x1;
}

long double sin_deg_dh(long double a){
	long double angle = PI_dh * (a / 180.0);
	long double retval = angle;
	long double n = 1.0;
	long double exp;

	while (n < 60.0) {
		exp = (2 * n) + 1;
		retval += ((pow_dh(-1, n) * pow_dh(angle, exp)) / factorial_dh(exp));
		n += 1.0;
	}
	return retval;
}

long double sin_rad_dh(long double a){
	long double retval = a;
	long double n = 1.0;
	long double exp;

	while (n < 60.0) {
		exp = (2 * n) + 1;
		retval += ((pow_dh(-1, n) * pow_dh(a, exp)) / factorial_dh(exp));
		n += 1.0;
	}
	return retval;
}

long double radtodeg_dh(long double a){
	return ((a / PI_dh) * 180.0);
}

long double degtorad_dh(long double a){
	return (PI_dh * (a / 180.0));
}

long double degtorad_spec_dh(long double a){
	return (a / 180.0);
}

long double pow_dh(long double a, long long exp) {
	long double retval = a;
	long long i = 1;

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

