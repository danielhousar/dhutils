
#include <stdio.h>
#include <string.h>
#include "../include/danh.h"
#include "../include/danhmath.h"

int quadequi_release = 0;
int quadequi_revision = 0;
char* quadequi_version = "0.0 2011-03-15";

int main (int argc, char **argv){
	int i = 0;
	int print_version = 0;
	int debug = 0;
	int print_help = 0;
	while (i < argc){
		if (strcmp(argv[i], "-V") == 0 || strcmp(argv[i], "--version") == 0) print_version = 1;
		if (strcmp(argv[i], "--debug") == 0) debug = 1;
		if (strcmp(argv[i], "--help") == 0) print_help = 1;
		i++;
	}
	
	if (print_help == 1 || argc == 1) puts("Usage: quadequi [--help] [--debug] [-V | --version] x y");

	if (print_version == 1) {
		printf("libdanh version: %s\n", libdanh_version);
		printf("quadequi version: %s\n", quadequi_version);
	}

	if (debug == 1) puts("debug mode is ON");

	return 0;
}
