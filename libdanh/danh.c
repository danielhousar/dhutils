/*****************************************************************************
 * file:	danh.c
 * revision:	2011-03-15
 ***************************************************************************** */

#include "../include/danh.h"

const int libdanh_version_major = 0;
const int libdanh_version_minor = 0;
const int libdanh_release = 6;

const char* libdanh_version = "0.0.6 2011-03-15 #1";

/* functions */

//nothing for now

/* functions - testing */

double str_to_double_dh(char* str){
	double retval = 0.0;
	double helpval = 0.0;
	int char_count = 0;

	while (str && str[char_count] != 0){
		char_count++;
	}

	int numbers[100];

	int position = char_count - 1;
	int i = 0;
	int j = 0;
	int index = 0;
	double divider = 1.0;

	while (i <= position){
		numbers[i] = str[i] - 48;
		i++;
	}

	while (j <= position){
		if (numbers[j] >= 0 && numbers[j] <= 9 && index == 0){
			retval *= 10.0;
			retval += numbers[j];
			j++;
		}
		else if (numbers[j] == -2){
			index = 1;
			j++;
		}
		else {
			divider *= 10.0;
			helpval += numbers[j] / divider;
			j++;
		}
	}

	retval += helpval;

	return retval;
}

/* under construction */

int strlength_dh(char* str){
	int i = 0;
	while(str && str[i] != 0){
		i++;
	}
	return i;
}

/*
char* double_to_str_dh(double a){
	char* retval;
	retval[0] = "1";
	retval[1] = ".";
	retval[2] = "0";
	return retval;
}
*/

