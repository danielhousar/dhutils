/*****************************************************************************
 * file:	libdanh/danh.c
 ***************************************************************************** */

#include "../include/danh.h"

const int dh_version = 0;
const int dh_release = 8;
const int dh_rev = 11;
const int dh_rev_date = 20110502;
const char* dh_version_string = "0.8 rev. 11 2011-05-02";


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

