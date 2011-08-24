#include <stdio.h>
#include <math.h>
#include "../include/dh.h"
#include "../include/dhmath.h"
#include "../include/dhstr.h"

#define ADD		1
#define MINUS	2
#define MULTIPLE	3
#define DIVIDE	4
#define INT		8
#define FLOAT	16



int dhc_add_i() {
	return 0;
}

/* main */

int main(int argc, char **argv) {
	int action = 0;
	char action_lock = 0;
	int arg = 1;
	int args_i[64];
	int args_i_count = 0;
#ifdef DH_DEBUG
	printf("start main()\n");
#endif

/* init */
	for (arg = 1; arg < argc; arg++) {
		if (!strcmp_dh(argv[arg], "+") && !action_lock) { action = 1; action_lock = 1; continue; }
		if (!strcmp_dh(argv[arg], "-") && !action_lock) { action = 2; action_lock = 1; continue; }
		if (!strcmp_dh(argv[arg], "*") && !action_lock) { action = 3; action_lock = 1; continue; }
		if (!strcmp_dh(argv[arg], "/") && !action_lock) { action = 4; action_lock = 1; continue; }
		if (s_is_num_dh(argv[arg])) { args_i[args_i_count] = snumrep_to_i_dh(argv[arg]); args_i_count++; }
	}

	switch (action) {
	case 1:
		printf("%d + %d = %d\n", args_i[0], args_i[1], args_i[0] + args_i[1]);
		break;
	default:
		break;
	}
#ifdef DH_DEBUG
	printf("end main() on return 0\n");
#endif
	return 0;
}


