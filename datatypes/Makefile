########################################
# file:	datatypes/Makefile
########################################

CC=gcc
CFLAGS=-march=native -mtune=native -O2 -Wall
DEFS=

all: binary

.PHONY: binary

binary:
	$(CC) $(CFLAGS) $(DEFS) main.c -o ../.bin/datatypes -L../.lib -ldh

