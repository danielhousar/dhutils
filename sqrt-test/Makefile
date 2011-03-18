
CC=gcc
CFLAGS=-march=native -mtune=native -O3

all: binary

.PHONY: binary objs

binary: objs
	$(CC) main.o -o ../bin/sqrt-test -L../bin -ldanh

objs:
	$(CC) $(CFLAGS) -c main.c
