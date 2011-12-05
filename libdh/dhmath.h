/******************************************************
 * file:	include/dhmath.h
 ****************************************************** */

#ifndef DHMATH_H
#define DHMATH_H

#include <math.h>
#include <complex.h>

#define PI_dh 3.14159265358979323846
#define E_dh 2.7182818284590452354

 double qe_roots[2];

/*
#ifdef HAVE_MATH_H
 __float128 factorial_f128_dh(__float128 a);
#endif
*/

 long double factorial_dh(long double a);
 float sqrtf_dh(float a);
 double sqrt_dh(double a);
 long double sqrt_fld_dh(long double a);
 double *quadequi_c_dh (double a, double b, double c, double *pf);
 double *quadequi_dh(double a, double b, double c);
 double quadequi_1_dh(double a, double b, double c);
 double quadequi_2_dh(double a, double b, double c);
 long double sin_deg_dh(long double a);
 long double sin_dh(long double a);
 long double cos_dh(long double ang);
 inline long double radtodeg_dh(long double a);
 inline long double degtorad_dh(long double a);
 inline long double degtorad_spec_dh(long double a);
 long double pow_dh(long double a, long long exp);

#endif

