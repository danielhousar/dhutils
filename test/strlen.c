#include <stdio.h>
#include "../include/dh.h"
#include "../include/dhstr.h"

int main(int argc, char **argv){
	if (argc > 1){
		printf("%i\n", strlen_dh(argv[1]));
	}
	return 0;
}

