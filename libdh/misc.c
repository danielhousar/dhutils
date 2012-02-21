/*****************************************************************************
 * file:	libdh/misc.c
 ***************************************************************************** */

#include <sys/time.h>
#include <time.h>
#include "dhmisc.h"

void ui2bins_t_dh(char *p, unsigned int a) {
	int pos = 0;
	unsigned int i = 0;
	unsigned int helpval = 0;

	while ((2 * helpval) < a) {
		helpval = 1 << i;
		i++;
	}

	while (helpval >= 1) {
		if (helpval <= a && 2 * helpval > a) {
			p[pos] = 49;
			a -= helpval;
		}
		else { p[pos] = 48; }
		helpval = helpval >> 1;
		pos++;
	}
	p[pos] = 0;
}

char *ui2bins_dh(char *p, unsigned int a) {
	char *retval = p;
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
			a -= helpval;
		}
		else { retval[pos] = 48; }
		helpval = helpval >> 1;
		pos++;
	}
	retval[pos] = 0;
	return retval;
}

unsigned long rand_dh() {
	unsigned long ret_rand;
	struct timeval tod;
	unsigned long time;

	gettimeofday(&tod, 0);
	ret_rand = tod.tv_usec;
	while (ret_rand > 127) {
		ret_rand = ret_rand / 10;
	}

	return ret_rand;
}

void wait (int seconds) {
  clock_t endwait;
  endwait = clock () + seconds * CLOCKS_PER_SEC ;
  while (clock() < endwait) {}
}
