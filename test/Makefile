
CC=gcc
CFLAGS=-march=native -mtune=native -O3

all:

.PHONY: binary

sqrt:
	$(CC) $(CFLAGS) sqrt.c -o sqrt -L../.lib -ldanh

convert:
	$(CC) $(CFLAGS) convert.c -o convert -L../.lib -ldanh
	
split:
	$(CC) $(CFLAGS) split.c -o split -L../libdanh -ldanh

