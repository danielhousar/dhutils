
CC=gcc
CFLAGS=-march=native -mtune=native -O3

all:

.PHONY: sqrt convert

sqrt:
	$(CC) $(CFLAGS) sqrt.c -o sqrt -L../.lib -ldanh

convert:
	$(CC) $(CFLAGS) convert.c -o convert -L../.lib -ldanh
	
