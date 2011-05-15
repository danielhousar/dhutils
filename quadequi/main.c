/***************************************************************
 * file:	quadequi/main.c
 ***************************************************************/

#include <stdio.h>
#include "../include/dh.h"
#include "../include/dhmath.h"
#include "../include/types.h"


int main (int argc, char **argv){

	const char* qe_version_str = "0.10 2011-05-14";

	int i = 1;
	char var_set = 0;
	char qe_init = 0;
	double a = 0.0;
	double b = 0.0;
	double c = 0.0;
	double main_x1 = 0.0;
	double main_x2 = 0.0;


/* init */
	if (argc == 1){
		printf("Usage: %s [--help]|[--version] a b c\n", argv[0]);
		return 0;
	}
	else {
		while (i < argc){
			if (argv[i][0] == '-') {
				if (!strcmp_dh(argv[i], "--help") || argv[i][1] == 'h') { qe_init += 1; }
				if (!strcmp_dh(argv[i], "--version") || argv[i][1] == 'v') { qe_init += 2; }
			}

			if (s_is_num_dh(argv[i]) == 1) {
				switch (var_set){
					case 0:
						a = sdecrep_to_fd_dh(argv[i]);
						break;
					case 1:
						b = sdecrep_to_fd_dh(argv[i]);
						break;
					case 2:
						c = sdecrep_to_fd_dh(argv[i]);
						break;
				}
				var_set++;
			}

			i++;
		}
/* output */
		if (qe_init == 1) {
			printf("Usage: %s [--help]|[--version] a b c\n", argv[0]);
			if (var_set < 1) puts("a not set");
			if (var_set < 2) puts("b not set");
			if (var_set < 3) puts("c not set");
		}

		if (qe_init > 1) {
			printf("libdh %i.%i %i\n", dh_version, dh_release, dh_rev);
			printf("quadequi %s\n", qe_version_str);
		}

		if (var_set > 0) {
			if (var_set < 3) puts("not all required values given - stop processing");
			else {
				main_x1 = quadequi_dh(a, b, c, 1);
				main_x2 = quadequi_dh(a, b, c, 2);

				printf(" x1 = %f\n x2 = %f\n", main_x1, main_x2);
			}
		}
	}

	return 0;
}

