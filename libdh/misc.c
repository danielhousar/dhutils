/*****************************************************************************
 * file:	libdh/misc.c
 ***************************************************************************** */

#include <sys/time.h>
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

void wait (int seconds) {
  clock_t endwait;
  endwait = clock () + seconds * CLOCKS_PER_SEC ;
  while (clock() < endwait) {}
}
