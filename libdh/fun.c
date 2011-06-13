/*****************************************************************************
 * file:	libdh/fun.c
 *
 * description:	various functions for fun
 *
 ***************************************************************************** */

#include "../include/dhfun.h"

/* mad_d_dh()
 * Returns ((2 * a) / 3).
 * In the fact: the main loop converges to ((2 * a) / 3), but the return value
 * depends on count of loops.
 * Do you know more stupid algorithm?
 */
double mad_d_dh(double a){
	double retval = a;
	double helper1 = a;
	double helper2 = 0;
	char count = 48;
	char counter = 0;
	while (counter < count){
		retval = (helper1 + helper2) / 2.00;
		helper2 = retval;
		helper1 = (helper1 + helper2) / 2.00;
		retval = helper1;
		counter++;
	}
	return retval;
}

