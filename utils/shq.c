/***************************************************************
 * file:	shq/main.c
 *************************************************************** */
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char **argv) {
	int i = 0;
	scanf("%i", &i);
	printf("%i\n", i);
	if (argc > 1 && i==1) {
		system(argv[1]);
		return 0;
	}
	else return 1;
}

