/*****************************************************************************
 * file:	libdanh/danh.c
 ***************************************************************************** */

#include "../include/danh.h"

const int libdanh_version_major = 0;
const int libdanh_release = 7;
const int libdanh_revision = 5;
const char* libdanh_version = "0.7 rev. 5 2011-03-19";


int strlength_dh(char* str){
	int i = 0;
	while(str && str[i] != 0){
		i++;
	}
	return i;
}

int strcmp_dh(char* str1, char* str2) {
	int i = 0;
	int retval = 0;
	if (strlength_dh(str1) != strlength_dh(str2)) {
		retval++;
	}
	else {
		while ((str1 || str2) && str1[i] != 0 && str2[i] != 0) {
			if (str1[i] != str2[i]) retval++;
			i++;
		}
	}
	return retval;
}


