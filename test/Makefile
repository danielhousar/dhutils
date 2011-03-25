
CC=gcc
CFLAGS=-march=native -mtune=native -O3

all: binary

.PHONY: binary

binary:
	$(CC) $(CFLAGS) sqrt.c -o sqrt -L../libdanh -ldanh

