/******************************************************
 * file:	include/dhmath.h
 ****************************************************** */

#ifndef DHMATH_H
#define DHMATH_H

#define PI_dh 3.14159265358979323846
#define E_dh 2.7182818284590452354

extern long double factorial_dh(long double a);
extern float sqrtf_dh(float a);
extern double sqrt_dh(double a);
extern long double sqrt_fld_dh(long double a);
extern double quadequi_dh(double a, double b, double c, int x);
extern long double sin_deg_dh(long double a);
extern long double sin_rad_dh(long double a);
extern long double radtodeg_dh(long double a);
extern long double degtorad_dh(long double a);
extern long double degtorad_spec_dh(long double a);
extern long double pow_dh(long double a, long long exp);

#endif

