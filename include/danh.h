/***************************************************************
 * file:	include/danh.h
 *************************************************************** */

#define LIBDANH
#define LIBDANH_VERSION_MAJOR 0
#define LIBDANH_RELEASE 8
#define LIBDANH_REVISION 4

const int libdanh_version_major;
const int libdanh_release;
const int libdanh_revision;
const char* libdanh_version;

int strlength_dh(char* str);

int strcmp_dh(char* str1, char* str2);

// char** ssplit_dh(char* s, char separator);

