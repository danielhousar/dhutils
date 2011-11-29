/***************************************************************
 * file:	utils/fc.c
 *************************************************************** */
#include <stdio.h>
#include <stdlib.h>

void func_fc ( void (*f)(int), int a );

void func_fc ( void (*f)(int), int a ) {
	(*f)(a);
}

int main (int argc, char **argv) {
	void *i = 0;

	scanf("%p", &i);
	printf("%p\n", printf("debil"));
	return 0;
}

