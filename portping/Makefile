########################################
# file:	portping/Makefile
########################################

CC=gcc
CFLAGS=-march=native -mtune=native -O3 -Wall
DEFS=

all: binary

.PHONY: binary

binary:
	$(CC) $(CFLAGS) $(DEFS) main.c -o ../.bin/portping -L../.lib -ldanh

