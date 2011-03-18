/*****************************************************************************
 * file:	danh.c
 ***************************************************************************** */

#include "../include/danh.h"

const int libdanh_version_major = 0;
const int libdanh_release = 7;
const int libdanh_revision = 3;
const char* libdanh_version = "0.7 rev. 3 2011-03-18";

/* functions */

//nothing for now

/* functions - testing */

double str_to_double_dh(char* str){
	double retval = 0.0;
	double helpval = 0.0;
	int char_count = 0;
	int i = 0;
	int j = 0;
	double divider = 1.0;
	int numbers[100];
	int position;
	int is_negative = 0;
	int is_spot = 0;

	while (str && str[char_count] != 0)
		char_count++;

	position = char_count - 1;

	while (i <= position){
		numbers[i] = str[i] - 48;
		i++;
	}

	while (j <= position){
		if (numbers[j] >= 0 && numbers[j] <= 9 && is_spot == 0){
			retval *= 10.0;
			retval += numbers[j];
			j++;
		}
		else if (numbers[j] == -3){
			is_negative = 1;
			j++;
		}
		else if (numbers[j] == -2){
			is_spot = 1;
			j++;
		}
		else {
			divider *= 10.0;
			helpval += numbers[j] / divider;
			j++;
		}
	}

	retval += helpval;
	if (is_negative == 1)
		retval *= -1.0;

	return retval;
}

int strlength_dh(char* str){
	int i = 0;
	while(str && str[i] != 0){
		i++;
	}
	return i;
}

/* under construction */

/*
char* double_to_str_dh(double a){
	char* retval;
	retval[0] = "1";
	retval[1] = ".";
	retval[2] = "0";
	return retval;
}
*/

