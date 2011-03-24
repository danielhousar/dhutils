########################################
# file:	quadequi/Makefile
########################################

CC=gcc
CFLAGS=-march=native -mtune=native -O3

all: binary

.PHONY: binary objs

binary:
	$(CC) $(CFLAGS) main.c -o ../bin/quadequi -L../bin -ldanh

