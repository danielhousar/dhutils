#include <stdio.h>
#include <math.h>

int main (int argc, char **argv) {
	int pos = 0;
	int num = 453872;
	int numarray[6] = { 0, 0, 0, 0, 0, 0 };

/*
	1 2 4 8 16 32 64
*/

	while (pos < 6) {
		numarray[pos] = num % 10;
		num /= 10;
		pos++;
	}

	printf("%d\n", numarray[0]);

	return 0;
}


