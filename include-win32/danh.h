/***************************************************************
 * file:	danh.h
 *
 * Header of danh library.
 * Danh library is custom library with some usable functions.
 *************************************************************** */

#define LIBDANH
#define LIBDANH_VERSION_MAJOR 0
#define LIBDANH_VERSION_MINOR 0
#define LIBDANH_RELEASE 7

__declspec( dllexport ) const int libdanh_version_major;
__declspec( dllexport ) const int libdanh_version_minor;
__declspec( dllexport ) const int libdanh_release;
__declspec( dllexport ) const int libdanh_revision;
__declspec( dllexport ) const char* libdanh_version;

/* functions */

//no functions for now

/* functions - testing */

__declspec( dllexport ) double str_to_double_dh(char* str);

__declspec( dllexport ) int strlength_dh(char* str);

/* functions - under construction */

//char* double_to_str_dh(double a);

