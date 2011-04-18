
CC=gcc
CFLAGS=-march=native -mtune=native -O3
DEFS=

all:

.PHONY: sqrt convert power

sqrt:
	$(CC) $(CFLAGS) $(DEFS) sqrt.c -o sqrt -L../.lib -ldanh

convert:
	$(CC) $(CFLAGS) $(DEFS) convert.c -o convert -L../.lib -ldanh

power:
	$(CC) $(CFLAGS) $(DEFS) power.c -o power -L../.lib -ldanh
