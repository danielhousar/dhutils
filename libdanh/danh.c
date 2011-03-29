/*****************************************************************************
 * file:	libdanh/danh.c
 ***************************************************************************** */

#include "../include/danh.h"

const int libdanh_version_major = 0;
const int libdanh_release = 8;
const int libdanh_revision = 5;
const char* libdanh_version = "0.8 rev. 5 2011-03-25";


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
/*
char** ssplit_dh(char* s, char separator) {
	printf("entering in function: %s %d\n", s, separator);
	char helpval[48][48];
	char** retval;
	int i = 0;
	int j = 0;
	int k = 0;
	puts("variables set");

	while (s && s[i] != 0) {
		printf("cycle %d, char %d, j %d, k %d\n", i, s[i], j, k);
		helpval[j][k] = s[i];
		puts("char added");
		k++;
		if (s[i] == separator) {
			puts("separator");
			//helpval[j][k] = 0;
			j++;
			k = 0;
		}
		i++;
	}
	retval = (char**) helpval;
	printf("end of function\n");
	return retval;
}
*/

