/*****************************************************************************
 * file:	libdh/misc.c
 ***************************************************************************** */

# include "../include/dhmisc.h"

char binrep_chars[64];

char *ui_to_binrep_dh(unsigned int a) {
	char *retval = &binrep_chars;
	int pos = 0;
	unsigned int i = 0;
	unsigned int helpval = 0;

	while ((2 * helpval) < a) {
		helpval = 1 << i;
		i++;
	}

	while (helpval >= 1) {
		if (helpval <= a && 2 * helpval > a) {
			binrep_chars[pos] = 49;
			a = a - helpval;
		}
		else { binrep_chars[pos] = 48; }
		helpval = helpval >> 1;
		pos++;
	}
	binrep_chars[pos] = 0;
	return retval;
}

