/*****************************************************************************
 * file:	libdh/str.c
 ***************************************************************************** */

#include "../include/dhstr.h"

double sdecrep_to_fd_dh(char *s){
	double retval = 0.0;
	int i = 0;
	double divider = 1.0;
	double sign = 1.0;
	int was_point = 0;

	if (s[0] == 45) { i = 1; sign = -1.0; }

	while (s[i] != 0 && i < 64) {
		if (s[i] >= 48 && s[i] <= 57){
			if (was_point == 0) {
				retval *= 10.0;
				retval += (s[i] - 48);
			}
			else {
				divider *= 10.0;
				retval += ((s[i] - 48) / divider);
			}
		}

		if (s[i] == 46){
			was_point = 1;
		}

		i++;
	}

	retval *= sign;

	return retval;
}

long double sdecrep_to_fld_dh(char *s){
	long double retval = 0.0;
	int i = 0;
	long double divider = 1.0;
	long double sign = 1.0;
	int was_point = 0;

	if (s[0] == 45) { i = 1; sign = -1.0; }

	while (s[i] != 0 && i < 64) {
		if (s[i] >= 48 && s[i] <= 57){
			if (was_point == 0) {
				retval *= 10.0;
				retval += (s[i] - 48);
			}
			else {
				divider *= 10.0;
				retval += ((s[i] - 48) / divider);
			}
		}

		if (s[i] == 46){
			was_point = 1;
		}

		i++;
	}

	retval *= sign;

	return retval;
}

int shexrep_to_i_dh(char *s){
	int retval = 0;
	int i = 2;

	while (s[i] != 0) {
		retval *= 16;
		if(s[i] > 47 && s[i] < 58) { retval += (s[i] - 48); }
		else if (s[i] > 64 && s[i] < 71) { retval += (s[i] - 55); }
		else if (s[i] > 96 && s[i] < 103) { retval += (s[i] - 87); }

		i++;
	}

	if (s[0] == 49) retval *= -1;

	return retval;
}

long shexrep_to_li_dh(char *s){
	long retval = 0;
	int i = 2;

	while (s[i] != 0) {
		retval *= 16;
		if(s[i] > 47 && s[i] < 58) { retval += (s[i] - 48); }
		else if (s[i] > 64 && s[i] < 71) { retval += (s[i] - 55); }
		else if (s[i] > 96 && s[i] < 103) { retval += (s[i] - 87); }

		i++;
	}

	if (s[0] == 49) retval *= -1;

	return retval;
}

int snumrep_to_i_dh(char *s){
	int retval = 0;
	int i = 0;
	int sign = 1;

	if (s[0] == 45) { i = 1; sign = -1; }

	while (s[i] != 0 && i < 64) {
		if (s[i] >= 48 && s[i] <= 57){
			retval *= 10;
			retval += (s[i] - 48);
		}
		i++;
	}

	retval *= sign;

	return retval;
}

unsigned int sbinrep_to_ui_dh(char *s){
	unsigned int retval = 0;
	int i = 0;
	int len = strlen_dh(s);

	while (i < len) {
		if (s[i] == 49) {
			retval += 1 << (len - i - 1);
		}
		i++;
	}

	return retval;
}

int s_is_num_dh(char* s){
	int i = 0;
	int err_nu = 0;
	int was_point = 0;

	if (s[i] == 45) { i++; }

	while (s && s[i] != 0 && err_nu == 0){
		if (s[i] < 46 || s[i] == 47 || s[i] > 57) { err_nu++; }

		if (s[i] == 46){
			if (was_point == 0) { was_point = 1; }
			else { err_nu++; }
		}
		i++;
	}

	if (err_nu == 0) return 1;
	else return 0;
}

int s_is_hex_dh(char *s) {
	int i = 0;
	int err_nu = 0;

	if (strlen_dh(s) < 3) { return 0; }

	if (s[i] > 49 || s[i] < 48) { return 0; }
	i++;

	if (s[i] != 120) { return 0; }
	i++;

	while (s && s[i] != 0 && err_nu == 0){
		if (s[i] < 48 || s[i] > 57) {
			if (s[i] < 65 || s[i] > 70) {
				if (s[i] < 97 || s[i] > 102) err_nu++;
			}
		}
		i++;
	}

	if (err_nu == 0) return 1;
	else return 0;
}
