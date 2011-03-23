/***************************************************************
 * file: quadequi/main.c
 ***************************************************************/

#include <stdio.h>
#include "../include/danh.h"
#include "../include/danhmath.h"
#include "../include/types.h"

int quadequi_release = 0;
int quadequi_revision = 4;
char* quadequi_version = "0.4 2011-03-19";

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
		if (strcmp_dh(argv[i], "--help") == 0) qe_init += 1;
		if (strcmp_dh(argv[i], "--version") == 0) qe_init += 2;
		if (strcmp_dh(argv[i], "--debug") == 0) qe_init += 4;
		
		if (str_is_number_dh(argv[i]) == 1) {
			if (var_set == 0){
				a = str_to_double_dh(argv[i]);
			}
			else if (var_set == 1) {
				b = str_to_double_dh(argv[i]);
			}
			else if (var_set == 2){
				c = str_to_double_dh(argv[i]);
			}
			var_set++;
		}

		i++;
	}
	
	if (qe_init == 1 || argc == 1) puts("Usage: quadequi [--help]|[--debug] [--version] a b c");

	if (qe_init > 1) {
		printf("libdanh version: %s\n", libdanh_version);
		printf("quadequi version: %s\n", quadequi_version);
	}
	if (qe_init > 3) puts("debug mode is ON");
	
	if (var_set < 1) puts("a not set");
	if (var_set < 2) puts("b not set");
	if (var_set < 3) puts("c not set");
	
	if (qe_init > 3 && var_set > 0) {
		printf("a: %lG\n", a);
		if (var_set >= 2) printf("b: %lG\n", b);
		if (var_set >= 3) printf("c: %lG\n", c);
	}
	
	if (var_set >= 3){
		main_x1 = quadequi_double_dh(a, b, c, 1);
		main_x2 = quadequi_double_dh(a, b, c, 2);

		printf("x1 = %lG\nx2 = %lG\n", main_x1, main_x2);
	}
	else if (var_set > 0) puts("not all required values given - stop processing");

	return 0;
}

