/***************************************************************
 * file:	include/danh.h
 *************************************************************** */

#define LIBDANH
#define LIBDANH_VERSION_MAJOR 0
#define LIBDANH_RELEASE 8
#define LIBDANH_REVISION 10

extern const int dh_version;
extern const int dh_release;
extern const int dh_rev;
extern const int dh_rev_date;
extern const char* dh_version_string;

extern int strlen_dh(char* str);

extern int strcmp_dh(char* str1, char* str2);

/******************************************************
 * file:	include/danhmath.h
 ****************************************************** */

extern const double PI_dh;

extern double factorial_fd_dh(double a);

extern float sqrt_f_dh(float a);

extern double sqrt_fd_dh(double a);

extern double mad_fd_dh(double a);

extern double quadequi_fd_dh(double a, double b, double c, int x);

extern double sin_deg_dh(double a);

extern double sin_rad_dh(double a);

extern double pow_dh(double a, double exp);

/***************************************************************
 * file:	include/types.h
 *************************************************************** */

extern double sdecrep_to_fd_dh(char* s);

extern long shexrep_to_li_dh(char* s);

extern int snumrep_to_i_dh(char* s);

extern int s_is_num_dh(char* s);

/***************************************************************
 * file:	datatypes/main.c
 ***************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//#include "../include/danhmath.h"
//#include "../include/danh.h"
//#include "../include/types.h"

int main (int argc, char **argv){
	puts("datatypes 0.3 2011-03-29");
	puts(" ");
	puts("----- ENVIRONMENT -----");
	puts(" ");
	puts("sizeof()");
	printf("short: %i\n", sizeof(short));
	printf("int: %i\n", sizeof(int));
	printf("long: %i\n", sizeof(long));
	printf("long long: %i\n", sizeof(long long));
	printf("float: %i\n", sizeof(float));
	printf("double: %i\n", sizeof(double));
	printf("long double: %i\n", sizeof(long double));
	printf("size_t: %i\n", sizeof(size_t));
	puts(" ");
	puts("-----------------------");
	puts(" ");

#ifdef WIN32
	puts("WIN32 defined");
#endif
#ifdef _WIN32
	puts("_WIN32 defined");
#endif
	puts(" ");
	return 0;
}
/*****************************************************************************
 * file:	libdanh/danh.c
 ***************************************************************************** */

#include "../include/danh.h"

const int dh_version = 0;
const int dh_release = 8;
const int dh_rev = 10;
const int dh_rev_date = 20110418;
const char* dh_version_string = "0.8 rev. 10 2011-04-18";


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

/******************************************************
 * file:	libdanh/math.c
 ****************************************************** */

#include "../include/danhmath.h"

const double PI_dh = 3.1415927;

double factorial_fd_dh(double a){
	double retval = 1.0;
	double i = 1.0;
	if (a <= 0 || a > 170) { retval = 0.0; }
	else {
		while (i <= a){
			retval *= i;
			i++;
		}
	}
	return retval;
}

float sqrt_f_dh(float a){
	int i = 0;
	float var1 = a;
	float var2 = 0.0;
	float var3;
	while ((var3 * var3) > a || (var3 * var3) < a) {
		var3 = (var1 + var2) / 2.0;
		if ((var3 * var3) > a) { var1 = var3; }
		else { var2 = var3; }
		i++;
	}
	return var3;
}

double sqrt_fd_dh(double a){
	int i = 0;
	double var1 = a;
	double var2 = 0.0;
	double var3;
	while ((var3 * var3) != a && i < 300) {
		var3 = (var1 + var2) / 2.0;
		if ((var3 * var3) > a) { var1 = var3; }
		else { var2 = var3; }
		i++;
		//printf("%.*f\t %d\n", 20, var3, i);
	}
	return var3;
}

double mad_fd_dh(double a){
	double retval = a;
	double helper1 = a;
	double helper2 = 0;
	int counter = 0;
	while (counter < 10){
		retval = (helper1 + helper2) / 2.00;
		helper2 = retval;
		helper1 = (helper1 + helper2) / 2.00;
		retval = helper1;
		counter++;
	}
	return retval;
}

double quadequi_fd_dh (double a, double b, double c, int x){
	double d, discr;
	double x1, x2;
	discr = (b * b) - (4.0 * a * c);

	if (discr < 0.0) {
		x1 = 0.0;
		x2 = 0.0;
	}

	else {
		d = sqrt_fd_dh(discr);
		x1 = (-b - d) / (2.0 * a);
		x2 = (-b + d) / (2.0 * a);
	}

	if (x == 2)
		return x2;
	else return x1;
}

double sin_deg_dh(double a){
	return 0.0;
}

double sin_rad_dh(double a){
	return 0.0;
}

double pow_dh(double a, double exp) {
	double retval = a;
	long i = 1;

	if (exp > 0){
		while (i < exp) {
			retval *= a;
			i++;
		}
	}

	return retval;
}
/*****************************************************************************
 * file:	libdanh/types.c
 ***************************************************************************** */

#include "../include/types.h"

double sdecrep_to_fd_dh(char* s){
	double retval = 0.0;
	int i = 0;
	double divider = 1.0;
	int numbers[48];
	int sign = 1.0;
	int was_point = 0;

	if (s[0] == 45) { i = 1; sign = -1.0; }

	while (s && s[i] != 0 && i < 48) {
		numbers[i] = s[i] - 48;

		if (numbers[i] >= 0 && numbers[i] <= 9){
			if (was_point == 0) {
				retval *= 10.0;
				retval += numbers[i];
			}
			else {
				divider *= 10.0;
				retval += numbers[i] / divider;
			}
		}

		if (numbers[i] == -2){
			was_point = 1;
		}

		i++;
	}

	retval *= sign;

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

int snumrep_to_i_dh(char* s){
	int retval = 0;
	int i = 0;
	int numbers[48];
	int is_negative = 0;

	if (s[0] == 45) { i = 1; numbers[0] = 0; is_negative = 1; }

	while (s && s[i] != 0 && i < 48) {
		numbers[i] = s[i] - 48;
		if (numbers[i] >= 0 && numbers[i] <= 9){
			retval *= 10;
			retval += numbers[i];
		}
		i++;
	}

	if (is_negative == 1)
		retval *= -1;

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


/***************************************************************
 * file: quadequi/main.c
 ***************************************************************/

#include <stdio.h>
#include "../include/danh.h"
#include "../include/danhmath.h"
#include "../include/types.h"

const char* qe_version_string = "0.9 2011-04-25";

int main (int argc, char **argv){
	int i = 0;
	int var_set = 0;
	int qe_init = 0;
	double a;
	double b;
	double c;
	double main_x1;
	double main_x2;

	while (i < argc){
		if (argv[i][0] == '-') {
			if (strcmp_dh(argv[i], "--help") == 0) qe_init += 1;
			if (strcmp_dh(argv[i], "--version") == 0) qe_init += 2;
			if (strcmp_dh(argv[i], "--debug") == 0) qe_init += 4;
		}

		if (s_is_num_dh(argv[i]) == 1) {
			if (var_set == 0){
				a = sdecrep_to_fd_dh(argv[i]);
			}
			else if (var_set == 1) {
				b = sdecrep_to_fd_dh(argv[i]);
			}
			else if (var_set == 2){
				c = sdecrep_to_fd_dh(argv[i]);
			}
			var_set++;
		}

		i++;
	}

	if (qe_init == 1 || argc == 1) puts("Usage: quadequi [--help]|[--debug] [--version] a b c");

	if (qe_init > 1) {
		printf("libdanh %s\n", dh_version_string);
		printf("quadequi %s\n", qe_version_string);
	}

	puts(" ");
	if (argc > 1 && qe_init < 2) {
		if (var_set < 1) puts("a not set");
		if (var_set < 2) puts("b not set");
		if (var_set < 3) puts("c not set");
	}

	if (qe_init > 3 && var_set > 0) {
		printf("a: %lG\n", a);
		if (var_set >= 2) printf("b: %lG\n", b);
		if (var_set >= 3) printf("c: %lG\n", c);
	}

	if (var_set >= 3){
		main_x1 = quadequi_fd_dh(a, b, c, 1);
		main_x2 = quadequi_fd_dh(a, b, c, 2);

		printf(" x1 = %f\n x2 = %f\n", main_x1, main_x2);
	}
	else if (var_set > 0) puts("not all required values given - stop processing");

	return 0;
}

/* 421 lines of code */
