/***************************************************************
 * file:	datatypes/main.c
 ***************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>
#include <limits.h>
#include <assert.h>
#include "../include/dh.h"

int main (int argc, char **argv){
	puts("datatypes 0.9 2011-05-06");
	puts(" ");
	puts("----- ENVIRONMENT -----");
	puts(" ");
	puts("sizeof()");
	puts(" ");
#ifdef _WIN32
	printf("char: %u\n", sizeof(char));
	printf("short: %u\n", sizeof(short));
	printf("int: %u\n", sizeof(int));
	printf("long: %u\n", sizeof(long));
	printf("long long: %u\n", sizeof(long long));
	printf("float: %u\n", sizeof(float));
	printf("double: %u\n", sizeof(double));
	printf("long double: %u\n", sizeof(long double));
	printf("size_t: %u\n", sizeof(size_t));
#else
	printf("char: %lu\n", sizeof(char));
	printf("short: %lu\n", sizeof(short));
	printf("int: %lu\n", sizeof(int));
	printf("long: %lu\n", sizeof(long));
	printf("long long: %lu\n", sizeof(long long));
	printf("float: %lu\n", sizeof(float));
	printf("double: %lu\n", sizeof(double));
	printf("long double: %lu\n", sizeof(long double));
	printf("size_t: %lu\n", sizeof(size_t));
#endif
	puts(" ");
	puts("------- MACROS --------");
	puts(" ");

#ifdef WIN32
	puts("WIN32 defined");
#endif
#ifdef _WIN32
	puts("_WIN32 defined");
#endif

#ifdef __MINGW32__
	puts("__MINGW32__ defined");
	printf("__MINGW32_MAJOR_VERSION %i\n", __MINGW32_MAJOR_VERSION);
	printf("__MINGW32_MINOR_VERSION %i\n", __MINGW32_MINOR_VERSION);
#endif

#ifdef __GNUC__
	printf("__GNUC__ %i\n", __GNUC__);
	printf("__GNUC_MINOR__ %i\n", __GNUC_MINOR__);
	printf("__GNUC_PATCHLEVEL__ %i\n", __GNUC_PATCHLEVEL__);
#endif

	puts(" ");

#ifdef __WORDSIZE
	printf("__WORDSIZE %i\n", __WORDSIZE);
#endif

#ifdef M_PI
	printf("M_PI = %f", M_PI);
#endif

	puts(" ");
	puts("------- LIBDH -------");
	puts(" ");
#ifdef LIBDH
	printf("dh.h version: %i %i %i\n", LIBDH_VERSION_MAJOR, LIBDH_RELEASE, LIBDH_REVISION);
	printf("libdh version: %i %i %i %i\n", dh_version, dh_release, dh_rev, dh_rev_date);
#endif
	puts(" ");
	puts("-----------------------");

	puts(" ");
	return 0;
}
