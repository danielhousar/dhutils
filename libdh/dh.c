/*****************************************************************************
 * file:	libdh/dh.c
 ***************************************************************************** */

#include "../include/dh.h"

const int dh_version = 0;
const int dh_release = 9;
const int dh_rev = 3;
const int dh_rev_date = 20110510;
const char* dh_version_string = "0.9.3 2011-05-10";


int strlen_dh(char* str){
	int i = 0;
	while(str[i] != 0){
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
		while (str1[i] != 0 && str2[i] != 0) {
			if (str1[i] != str2[i]) retval++;
			i++;
		}
	}
	return retval;
}

