/***************************************************************
 * file:	datatypes/main.c
 ***************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <limits.h>

#ifdef _WIN32
#include <windows.h>
#endif

#include "../include/dh.h"

int main (int argc, char **argv){
	printf("datatypes 0.14 2011-06-10\n\n");

#if defined _WIN32 || __WORDSIZE == 32
	printf("char: %u\n", sizeof(char));
	printf("short: %u\n", sizeof(short));
	printf("int: %u\n", sizeof(int));
	printf("long: %u\n", sizeof(long));
	printf("long long: %u\n", sizeof(long long));
	printf("float: %u\n", sizeof(float));
	printf("double: %u\n", sizeof(double));
	printf("long double: %u\n", sizeof(long double));
	printf("size_t: %u\n", sizeof(size_t));
	printf("void *: %u\n", sizeof(void *));
	printf("int *: %u\n", sizeof(int *));
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
	printf("void *: %lu\n", sizeof(void *));
	printf("int *: %lu\n", sizeof(int *));
#endif

	puts(" ");

#if defined BIG_ENDIAN || defined __BIG_ENDIAN || defined _BIG_ENDIAN || defined __BIG_ENDIAN__
	puts("arch has BIG_ENDIAN");
#endif
#if defined LITTLE_ENDIAN || defined __LITTLE_ENDIAN || defined _LITTLE_ENDIAN || defined __BIG_ENDIAN__
	puts("arch has LITTLE_ENDIAN");
#endif
#if defined _X86 || defined __X86__ || defined __X86 || defined _X86_ || defined X86 || defined x86 || defined __x86__
	puts("arch is x86");
#endif
#if defined _X86_64 || defined __X86_64__ || defined __X86_64 || defined _X86_64_ || defined X86_64 || defined x86_64 ||defined __x86_64__
	puts("arch is x86_64");
#endif
#if defined CHAR_BIT
	printf("char (byte) bits: %i\n", CHAR_BIT);
#elif defined __CHAR_BIT__
	printf("char (byte) bits: %i\n", __CHAR_BIT__);
#endif

#if defined _WIN32 || defined WIN32
	puts("system is WIN32");
	#ifdef _WIN64
		puts("system is MS Windows x64");
	#endif
	#ifdef _M_IX86
	printf("_M_IX86 %i\n", _M_IX86);
	#endif
	#ifdef _M_X64
	puts("_M_X64");
	#endif
	#ifdef _MSC_VER
	printf("compiller is MSVC %i", _MSC_VER);
	#endif
	#ifdef __MINGW32__
	printf("MinGW32 %i %i\n", __MINGW32_MAJOR_VERSION, __MINGW32_MINOR_VERSION);
	#endif
#endif

#if defined __unix__ || defined __unix || defined unix || defined _unix || defined _unix_
	puts("system is UNIX");
#endif

#if defined __linux__ || defined __linux || defined linux || defined _linux || defined _linux_
	puts("system is Linux");
#endif

#if defined GLIBC || defined _GLIBC_ || defined __GLIBC__
	puts("C library is GLIBC");
#endif

#ifdef __GNUC__
	printf("compiller is GCC %s\n", __VERSION__);
	#ifdef __WORDSIZE
	printf("__WORDSIZE %i\n", __WORDSIZE);
	#endif
	#ifdef __ELF__
	puts("ELF binary");
	#endif
#endif

	puts(" ");
#ifdef LIBDH
	printf("dh.h version: %i %i %i\n", LIBDH_VERSION, LIBDH_RELEASE, LIBDH_REVISION);
	printf("libdh version: %i %i %i\n", dh_version, dh_release, dh_rev);
#endif
	puts(" ");

	return 0;
}
