########################################
# file:	quadequi/Makefile
########################################

CC=gcc
CFLAGS=-march=native -mtune=native -O3 -Wall
DEFS=

all: binary

.PHONY: binary

binary:
	$(CC) $(CFLAGS) $(DEFS) main.c -o ../.bin/quadequi -L../.lib -ldh

