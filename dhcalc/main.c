#include <stdio.h>
#include <math.h>
#include "../include/dh.h"
#include "../include/dhmath.h"
#include "../include/dhstr.h"

#define ADD		1
#define MINUS		2
#define MULTIPLE	3
#define DIVIDE		4
#define INT		8
#define FLOAT		16

/* main */

int main(int argc, char **argv) {
	int action = 0;
	char action_lock = 0;
	int arg_type = 0;
	int arg = 1;

#ifdef DH_DEBUG
	printf("start main()\n");
#endif

/* init */
	while (arg < argc) {
		if (!strcmp_dh(argv[arg], "+") && !action_lock) { action = 1; action_lock = 1; }
		if (!strcmp_dh(argv[arg], "-") && !action_lock) { action = 2; action_lock = 1; }
		if (!strcmp_dh(argv[arg], "*") && !action_lock) { action = 3; action_lock = 1; }
		if (!strcmp_dh(argv[arg], "/") && !action_lock) { action = 4; action_lock = 1; }
		if (s_is_num_dh(argv[arg]) == 1) arg_type = 8;

		arg++;
	}

#ifdef DH_DEBUG
	printf("end main() on return 0\n");
#endif
	return 0;
}


