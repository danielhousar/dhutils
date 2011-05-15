/*****************************************************************************
 * file:	libdh/misc.c
 ***************************************************************************** */

# include "../include/dh.h"

void print_ui_to_binrep_dh(unsigned int a) {
	char retval[64];
	int pos = 0;
	unsigned int i = 0;
	unsigned int helpval = 0;

	while ((2 * helpval) < a) {
		helpval = 1 << i;
		i++;
	}

	while (helpval >= 1) {
		if (helpval <= a && 2 * helpval > a) {
			retval[pos] = 49;
			a = a - helpval;
		}
		else { retval[pos] = 48; }
		helpval = helpval >> 1;
		pos++;
	}
	retval[pos] = 0;
	i = 0;
	while (retval[i] != 0) {
		printf("%c", retval[i]);
		i++;
	}
	puts(" ");
}

