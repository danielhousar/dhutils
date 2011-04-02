########################################
# file:	quadequi/Makefile
########################################

CC=gcc
CFLAGS=-march=native -mtune=native -O3 -Wall

all: binary

.PHONY: binary

binary:
	$(CC) $(CFLAGS) main.c -o ../.bin/quadequi -L../.lib -ldanh

