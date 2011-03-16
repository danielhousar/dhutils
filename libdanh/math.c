/******************************************************
 * file:	math.c
 ****************************************************** */

#include "../include/danhmath.h"

int factorial_int_dh(int a){
	int retval = 1;
	if (a <= 0 || a > 16) { return 0; }
	else {
		int i = 1;
		while (i <= a){
			retval *= i;
			i++;
		}
	}
	return retval;
}

double factorial_double_dh(double a){
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

float misc_sqrt_dh(float a){
	float var1 = a;
	float var2 = 0.0;
	float var3;
	while ((var3 * var3) > a || (var3 * var3) < a) {
		var3 = (var1 + var2) / 2.0;
		if ((var3 * var3) > a) { var1 = var3; }
		else { var2 = var3; }
	}
	return var3;
}

double sqrt_double_dh(double a){
	double retval = 0.0;

	while ((retval * retval) < a){
		retval += 100.0;
	}
	if ((retval * retval) > a){ retval -=100.0; }

	while ((retval * retval) < a){
		retval += 10.0;
        }
        if ((retval * retval) > a){ retval -=10.0; }

	while ((retval * retval) < a){
                retval += 1.0;
        }
        if ((retval * retval) > a){ retval -=1.0; }

	if ((retval * retval) == a){ return retval; }
	else {
		while ((retval * retval) < a){
                	retval += 0.1;
        	}
        	if ((retval * retval) > a){ retval -=0.1; }

		while ((retval * retval) < a){
                	retval += 0.01;
                }
                if ((retval * retval) > a){ retval -=0.01; }

		while ((retval * retval) < a){
			retval += 0.001;
		}
		if ((retval * retval) > a){ retval -=0.001; }

		while ((retval * retval) < a){
			retval += 0.0001;
		}
		if ((retval * retval) > a){ retval -=0.0001; }

		while ((retval * retval) < a){
			retval += 0.00001;
		}
		if ((retval * retval) > a){ retval -=0.00001; }

		while ((retval * retval) < a){
			retval += 0.000001;
		}
		if ((retval * retval) > a){ retval -=0.000001; }

		while ((retval * retval) < a){
			retval += 0.0000001;
		}
		if ((retval * retval) > a){ retval -=0.0000001; }

		return retval;
	}
}

double mad_double_dh(double a){
	double retval = a;
	double helper1 = a;
	double helper2 = 0;
	int counter = 0;
	while (counter < 10){
		retval = (helper1 + helper2) / 2;
		helper2 = retval;
		helper1 = (helper1 + helper2) / 2;
		retval = helper1;
		counter++;
	}
	return retval;
}

/******************************************************************
double quadequi_double_dh (double a, double b, double c) [] {
	double d, discr;
	double x1, x2;
	double retval[2] = {x1, x2};
	discr = (b * b) - (4.0 * a * c);

	if (discr < 0.0) {
		double div;
		div = 2.0 * a;
		discr *= -1.0;
		d = sqrt_double_dh(discr);
		d /= div;
		b = b * -1.0 / div;
	}

	else {
		d = sqrt_double_dh(discr);
		x1 = (-b - d) / (2.0 * a);
		x2 = (-b + d) / (2.0 * a);
	}

	// return * retval;
	return {x1,x2};
}
*****************************************************************/

