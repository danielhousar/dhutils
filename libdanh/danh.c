/*****************************************************************************
 * file:	libdanh/danh.c
 ***************************************************************************** */

#include "../include/danh.h"

const int dh_version = 0;
const int dh_release = 9;
const int dh_rev = 2;
const int dh_rev_date = 20110509;
const char* dh_version_string = "0.9 rev. 2 2011-05-09";


int strlen_dh(char* str){
	int i = 0;
	while(str && str[i] != 0){
		i++;
	}
	return i;
}

int strcmp_dh(char* str1, char* str2) {
	int i = 0;
	int retval = 0;
	if (strlen_dh(str1) != strlen_dh(str2)) {
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

