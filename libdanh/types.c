/*****************************************************************************
 * file:	libdanh/types.c
 ***************************************************************************** */

#include "../include/types.h"

double sdecrep_to_fd_dh(char* s){
	double retval = 0.0;
	int char_count = 0;
	int i = 0;
	double divider = 1.0;
	int numbers[48];
	int is_negative = 0;
	int was_point = 0;

	while (s && s[char_count] != 0 && char_count < 48) {
		numbers[char_count] = s[char_count] - 48;
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

long shexrep_to_li_dh(char *s){
	long retval = 0;
	int i = 2;
	int chars[48];

	chars[0] = 0;
	chars[1] = 0;

	while (s && s[i] != 0) {
		if(s[i] > 47 && s[i] < 58) { chars[i] = s[i] - 48; }
		else if (s[i] > 64 && s[i] < 71) { chars[i] = s[i] - 55; }
		else if (s[i] > 96 && s[i] < 103) { chars[i] = s[i] - 87; }
		else { chars[i] = 0; }

		retval *= 16;
		retval += chars[i];

		i++;
	}

	if (s[0] == 49) retval *= -1;

	return retval;
}

int s_is_num_dh(char* s){
	int i = 0;
	int err_nu = 0;
	int was_point = 0;
	while (s && s[i] != 0 && err_nu == 0){
		if (s[i] < 45 || s[i] == 47 || s[i] > 57) { err_nu++; }
		if (i > 0 && s[i] == 45) { err_nu++; }

		if (s[i] == 46){
			if (was_point == 0) { was_point = 1; }
			else { err_nu++; }
		}
		i++;
	}

	if (err_nu == 0) return 1;
	else return 0;
}

/* under construction */


