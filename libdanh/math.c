/******************************************************
 * file:	libdanh/math.c
 ****************************************************** */

#include "../include/danhmath.h"

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

double misc_sqrt_double_dh(double a){
	int i = 0;
	double var1 = a;
	double var2 = 0.0;
	double var3;
	while ((var3 * var3) > a || (var3 * var3) < a) {
		var3 = (var1 + var2) / 2.0;
		if ((var3 * var3) > a) { var1 = var3; }
		else { var2 = var3; }
		i++;
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

double quadequi_double_dh (double a, double b, double c, int x){
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
		d = sqrt_double_dh(discr);
		x1 = (-b - d) / (2.0 * a);
		x2 = (-b + d) / (2.0 * a);
	}

	if (x == 2)
		return x2;
	else return x1;
}

