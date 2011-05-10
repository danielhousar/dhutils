/***************************************************************
 * file: quadequi/main.c
 ***************************************************************/

#include <stdio.h>
#include "../include/dh.h"
#include "../include/dhmath.h"
#include "../include/types.h"


int main (int argc, char **argv){

	const char* qe_version_string = "0.10 2011-05-09";

	int i = 0;
	char var_set = 0;
	char qe_init = 0;
	double a = 0.0;
	double b = 0.0;
	double c = 0.0;
	double main_x1 = 0.0;
	double main_x2 = 0.0;


/* init */
	while (i < argc){
		if (argv[i][0] == '-') {
			if (!strcmp_dh(argv[i], "--help")) { qe_init += 1; }
			if (!strcmp_dh(argv[i], "--version")) { qe_init += 2; }
			if (!strcmp_dh(argv[i], "--debug")) { qe_init += 4; }
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

/* output */
	if (qe_init == 1 || argc == 1) {
		puts("Usage: quadequi [--help]|[--debug] [--version] a b c");
		return 0;
	}

	if (qe_init > 1) {
		printf("libdh %s\n", dh_version_string);
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

