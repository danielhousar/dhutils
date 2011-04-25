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

