/******************************************************
 * file:	libdh/math.c
 ****************************************************** */

#include "dhmath.h"

double qe_roots[2];

/*
#ifdef HAVE_MATH_H
__float128 factorial_f128_dh(__float128 a) {
	__float128 retval_fq = 1.0Q;
	float i = 1.0;

	if (a <= 0.0Q || a > 1755.0Q) { retval_fq = 0.0Q; }
	else {
		while (i <= a){
			retval_fq *= i;
			i += 1.0;
		}
	}
	return retval_fq;
}
#endif
*/

long double factorial_dh(long double a){
	long double retval = 1.0;
	float i = 1.0;
	if (a < 0.0 || a > 1754.0) { retval = 0.0; }
	else {
		while (i <= a){
			retval *= i;
			i += 1.0;
		}
	}
	return retval;
}

double factorial_fd_dh(double a){
	double retval = 1.0;
	float i = 1.0;
	if (a < 0.0 || a > 170.0) { retval = 0.0; }
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

double *quadequi_dh (double a, double b, double c) {
	double *qe_retval = qe_roots;
	double d, discr;

	discr = (b * b) - (4.0 * a * c);

	if (discr >= 0.0) {
		d = sqrt_dh(discr);
		qe_roots[0] = (-b - d) / (2.0 * a);
		qe_roots[1] = (-b + d) / (2.0 * a);
	}

	return qe_retval;
}

double *quadequi_c_dh (double a, double b, double c, double *pf) {
	double *qe_retval = pf;
	double d, discr;
	double i = 0.0;
	double r = 1.0;

	discr = (b * b) - (4.0 * a * c);

	if (discr < 0.0) {
		discr *= -1.0;
		i = 1.0;
		r = 0.0;
	}
	d = sqrt_dh(discr);

	qe_retval[0] = ((-b - (r*d)) / (2.0 * a));
	qe_retval[1] = (-d*i) / (2.0 * a);
	qe_retval[2] = ((-b + (r*d)) / (2.0 * a));
	qe_retval[3] = (d*i) / (2.0 * a);

	return qe_retval;
}

double quadequi_1_dh (double a, double b, double c){
	double d, discr;
	double root = 0.0;
	discr = (b * b) - (4.0 * a * c);

	if (discr >= 0.0) {
		d = sqrt_dh(discr);
		root = (-b - d) / (2.0 * a);
	}

	return root;
}

double quadequi_2_dh (double a, double b, double c){
	double d, discr;
	double root = 0.0;
	discr = (b * b) - (4.0 * a * c);

	if (discr >= 0.0) {
		d = sqrt_dh(discr);
		root = (-b + d) / (2.0 * a);
	}

	return root;
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

long double sin_dh(long double a){
	long double retval = a;
	long double n = 1.0;
	long double exp;

	while (n < 200.0) {
		exp = (2 * n) + 1;
		retval += ((pow_dh(-1, n) * pow_dh(a, exp)) / factorial_dh(exp));
		n += 1.0;
	}
	return retval;
}

long double cos_dh (long double ang){
	long double retval = 0;
	long double n = 0;
	long double exp;

	while (n < 200.0) {
		exp = (2 * n);
		retval += ((pow_dh(-1, n) * pow_dh(ang, exp)) / factorial_dh(exp));
		n += 1.0;
	}
	return retval;
}

inline long double radtodeg_dh(long double a){
	return ((a / PI_dh) * 180.0);
}

inline long double degtorad_dh(long double a){
	return (PI_dh * (a / 180.0));
}

inline long double degtorad_spec_dh(long double a){
	return (a / 180.0);
}

long double pow_dh(long double a, long long exp) {
	long double retval = 1.0;
	long long i = 1;

	if (exp < 0){
		exp *= -1;
		a = 1.0 / a;
	}

	while (i <= exp) {
		retval *= a;
		i++;
	}

	return retval;
}

