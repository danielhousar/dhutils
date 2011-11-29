/***************************************************************
 * file:	utils/shq.c
 *************************************************************** */
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char **argv) {
	int i = 0;
	if (argc > 1) {
		printf("do: %s ?\n", argv[1]);
		scanf("%i", &i);
		if (i==1)
			system(argv[1]);
		return 0;
	}
	else return 1;
}

