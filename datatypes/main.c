/***************************************************************
 * file:	datatypes/main.c
 ***************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>
#include <limits.h>
#include <assert.h>
#include "../include/danh.h"

int main (int argc, char **argv){
	puts("datatypes 0.8 2011-05-06");
	puts(" ");
	puts("----- ENVIRONMENT -----");
	puts(" ");
	puts("sizeof()");
	puts(" ");
	printf("short: %i\n", sizeof(short));
	printf("int: %i\n", sizeof(int));
	printf("long: %i\n", sizeof(long));
	printf("long long: %i\n", sizeof(long long));
	printf("float: %i\n", sizeof(float));
	printf("double: %i\n", sizeof(double));
	printf("long double: %i\n", sizeof(long double));
	printf("size_t: %i\n", sizeof(size_t));
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
#endif
#ifdef __MINGW32_MAJOR_VERSION
	printf("__MINGW32_MAJOR_VERSION %i\n", __MINGW32_MAJOR_VERSION);
#endif
#ifdef __MINGW32_MINOR_VERSION
	printf("__MINGW32_MINOR_VERSION %i\n", __MINGW32_MINOR_VERSION);
#endif

#ifdef __GNUC__
	printf("__GNUC__ %i\n", __GNUC__);
#endif

#ifdef __GNUC_MINOR__
	printf("__GNUC_MINOR__ %i\n", __GNUC_MINOR__);
#endif

#ifdef __GNUC_PATCHLEVEL__
	printf("__GNUC_PATCHLEVEL__ %i\n", __GNUC_PATCHLEVEL__);
#endif

	puts(" ");

#ifdef __WORDSIZE
	printf("__WORDSIZE %i\n", __WORDSIZE);
#endif

#ifdef PI
	printf("PI = %f", PI);
#endif

#ifdef M_PI
	printf("M_PI = %f", M_PI);
#endif

	puts(" ");
	puts("------- LIBDANH -------");
	puts(" ");
#ifdef LIBDANH
	printf("danh.h version: %i %i %i\n", LIBDANH_VERSION_MAJOR, LIBDANH_RELEASE, LIBDANH_REVISION);
	printf("libdanh version: %i %i %i %i\n", dh_version, dh_release, dh_rev, dh_rev_date);
#endif
	puts(" ");
	puts("-----------------------");

	puts(" ");
	return 0;
}
