########################################
# file:	datatypes/Makefile
########################################

CC=gcc
CFLAGS=-march=native -mtune=native -O2

all: binary

.PHONY: binary objs

binary: objs
	$(CC) main.o -o ../bin/datatypes

objs:
	$(CC) $(CFLAGS) -c main.c
