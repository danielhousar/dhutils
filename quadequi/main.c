/***************************************************************
 * file: quadequi/main.c
 ***************************************************************/

#include <stdio.h>
#include <string.h>
#include "../include/danh.h"
#include "../include/danhmath.h"

int quadequi_release = 0;
int quadequi_revision = 0;
char* quadequi_version = "0.0 2011-03-17";

int main (int argc, char **argv){
	int i = 0;
	int is_y = 0;
	int x_is_set = 0;
	int y_is_set = 0;
	int print_version = 0;
	int debug = 0;
	int print_help = 0;
	double x;
	double y;

	while (i < argc){
		if (strcmp(argv[i], "-V") == 0 || strcmp(argv[i], "--version") == 0) print_version = 1;
		if (strcmp(argv[i], "--debug") == 0) debug = 1;
		if (strcmp(argv[i], "--help") == 0) print_help = 1;
		if (argv[i][0] > 48 && argv[i][0] < 57 && is_y == 0){
			x = str_to_double_dh(argv[i]);
			x_is_set = 1;
			is_y = 1;
		}
		if (argv[i][0] > 48 && argv[i][0] < 57 && is_y == 1) {
			y = str_to_double_dh(argv[i]);
			y_is_set = 1;
		}
		i++;
	}
	
	if (print_help == 1 || argc == 1) puts("Usage: quadequi [--help] [--debug] [-V | --version] x y");

	if (print_version == 1) {
		printf("libdanh version: %s\n", libdanh_version);
		printf("quadequi version: %s\n", quadequi_version);
	}

	if (debug == 1) puts("debug mode is ON");
	if (debug == 1 && x_is_set == 1) printf("x: %lG\n", x);
	if (x_is_set == 0) puts("x not set");
	if (debug == 1 && y_is_set == 1) printf("y: %lG\n", y);
	if (y_is_set == 0)puts("y not set");
	return 0;
}

