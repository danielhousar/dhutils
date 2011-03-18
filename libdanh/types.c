/*****************************************************************************
 * file:	libdanh/types.c
 ***************************************************************************** */

#include "../include/types.h"

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

int str_is_number_dh(char* str){
	int i = 0;
	int err_nu = 0;
	int was_point = 0;
	while (str && str[i] != 0 && err_nu == 0){
		if (str[i] < 45 || str[i] == 47 || str[i] > 57) { err_nu++; }
		if (i > 0 && str[i] == 45) { err_nu++; }

		if (str[i] == 46){ 
			if (was_point == 0) { was_point = 1; }
			else { err_nu++; }
		}
		i++;
	}

	if (err_nu == 0) return 1;
	else return 0;
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

