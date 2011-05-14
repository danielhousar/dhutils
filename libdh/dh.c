/*****************************************************************************
 * file:	libdh/dh.c
 ***************************************************************************** */

#include "../include/dh.h"

const int dh_version = 0;
const int dh_release = 9;
const int dh_rev = 20110514;


int strlen_dh(char *s){
	int i = 0;
	while(s[i] != 0){
		i++;
	}
	return i;
}

int strcmp_dh(char *s1, char *s2) {
	int i = 0;
	int retval = 0;
	if (strlen_dh(s1) != strlen_dh(s2)) {
		retval++;
	}
	else {
		while (s1[i] != 0 && s2[i] != 0) {
			if (s1[i] != s2[i]) retval++;
			i++;
		}
	}
	return retval;
}

