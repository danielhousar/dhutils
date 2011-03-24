/*****************************************************************************
 * file:	libdanh/types.c
 ***************************************************************************** */

#include "../include/types.h"

double str_to_double_dh(char* str){
	double retval = 0.0;
	int char_count = 0;
	int i = 0;
	double divider = 1.0;
	int numbers[96];
	int is_negative = 0;
	int was_point = 0;

	while (str && str[char_count] != 0 && char_count < 96) {
		numbers[char_count] = str[char_count] - 48;
		char_count++;
	}

	if (numbers[0] == -3) { i = 1; is_negative = 1; }

	while (i < char_count){
		if (numbers[i] >= 0 && numbers[i] <= 9 && was_point == 0){
			retval *= 10.0;
			retval += numbers[i];
			i++;
		}
		else if (numbers[i] == -2){
			was_point = 1;
			i++;
		}
		else {
			divider *= 10.0;
			retval += numbers[i] / divider;
			i++;
		}
	}

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


