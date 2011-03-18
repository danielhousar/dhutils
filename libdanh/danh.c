/*****************************************************************************
 * file:	libdanh/danh.c
 ***************************************************************************** */

#include "../include/danh.h"

const int libdanh_version_major = 0;
const int libdanh_release = 7;
const int libdanh_revision = 4;
const char* libdanh_version = "0.7 rev. 4 2011-03-18";


int strlength_dh(char* str){
	int i = 0;
	while(str && str[i] != 0){
		i++;
	}
	return i;
}


