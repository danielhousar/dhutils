#include <stdio.h>
#include <libdh/dhmisc.h>
//#include <stdlib.h>
//#include <sys/time.h>
//#include <time.h>


/*
unsigned long rand_dh() {
	unsigned long ret_rand;
	struct timeval tod;
	//float rand_operative;
	unsigned long time;

	gettimeofday(&tod, 0);
	printf(" microseconds: %lu\n", tod.tv_usec);
	time = tod.tv_usec;
	time = time >> 1;
	gettimeofday(&tod, 0);
	time -= (tod.tv_usec >> 2);
	time /= 100;
	gettimeofday(&tod, 0);
	time += (tod.tv_usec / 100);
	time /= 100;
	ret_rand = time;

	return ret_rand;
}
*/

int main(int argc, char **argv){
	printf("\t%lu\n", rand_dh());
	return 0;
}

