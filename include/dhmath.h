/******************************************************
 * file:	include/dhmath.h
 ****************************************************** */

#ifndef DHMATH

#define DHMATH_H

extern const long double PI_dh;

extern const long double E_dh;

extern long double factorial_dh(long double a);

extern float sqrtf_dh(float a);

extern double sqrt_dh(double a);

extern long double sqrt_fld_dh(long double a);

extern double mad_d_dh(double a);

extern double quadequi_dh(double a, double b, double c, int x);

extern long double sin_deg_dh(long double a);

extern long double sin_rad_dh(long double a);

extern long double radtodeg_dh(long double a);

extern long double degtorad_dh(long double a);

extern long double degtorad_spec_dh(long double a);

extern long double pow_dh(long double a, long double exp);

#endif /* if not DHMATH */

