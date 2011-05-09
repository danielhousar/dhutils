/*****************************************************************************
 * file:	test/bits-learn.c
 ***************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>
#include <limits.h>
#include <assert.h>

int main(int argc, char **argv) {
	int c;
	/*
	 * 10100 (20)
	 * 01100 (12)
	 * ----------
	 * 00100 (4)
	 */
	 c = 20 & 12;
	printf("20 & 12 = %i\n", c);
	return 0;
}

