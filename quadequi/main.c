/***************************************************************
 * file:	quadequi/main.c
 ***************************************************************/

#include <stdio.h>
#include <libdh/dh.h>
#include <libdh/dhmath.h>
#include <libdh/dhstr.h>


int main (int argc, char **argv){

	const char* qe_version_str = "0.10 2011-08-24";

	int i = 1;
	char var_set = 0;
	char qe_init = 0;
	double a = 0.0;
	double b = 0.0;
	double c = 0.0;
	double *main_roots;

/* init */
	if (argc == 1){
		printf("Usage: %s [--help|-h]|[--version|-v] a b c\n", argv[0]);
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
			printf("Usage: %s [--help|-h]|[--version|-v] a b c\n", argv[0]);
			if (var_set < 1) puts("a not set");
			if (var_set < 2) puts("b not set");
			if (var_set < 3) puts("c not set");
		}

		if (qe_init > 1) {
			printf("libdh %i.%i %i.%i\n", dh_version, dh_release, dh_rev_date, dh_rev_num);
			printf("quadequi %s\n", qe_version_str);
		}

/* core */
		if (var_set > 0) {
			if (var_set < 3) puts("not all required values given - stop processing");
			else {
				main_roots = quadequi_dh(a, b, c);

				printf(" x1 = %f\n x2 = %f\n", main_roots[0], main_roots[1]);
			}
		}
	}

/* end */
	return 0;
}

