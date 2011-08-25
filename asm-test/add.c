#include <stdio.h>

inline int main(int argc, char **argv) {
	int a = 1;
	int b = 0;
	if (argc > 1) {
		b = argv[1][0] - 48;
	}
	printf("%d\n", a + b);
	getchar();
	return 0;
}
