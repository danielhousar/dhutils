/*****************************************************************************
 * file:	libdh/misc.c
 ***************************************************************************** */

#include <sys/time.h>
# include "dhmisc.h"

char binrep_chars[64];

char *ui_to_binrep_dh(unsigned int a) {
	char *retval = binrep_chars;
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


unsigned long rand_dh() {
	unsigned long ret_rand;
	struct timeval tod;
	//float rand_operative;
	unsigned long time;

	gettimeofday(&tod, 0);
	time = tod.tv_usec;
	time = time >> 1;
	gettimeofday(&tod, 0);
	time -= (tod.tv_usec >> 2);
	time /= 100;
	gettimeofday(&tod, 0);
	time += (tod.tv_usec / 100);
	time /= 100;
	if (time >= 100)
		time = time >> 1;
	ret_rand = time;

	return ret_rand;
}

