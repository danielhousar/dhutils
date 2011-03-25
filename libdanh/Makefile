########################################################
# file:	libdanh/Makefile
########################################################

CC=gcc
CFLAGS=-march=native -mtune=native -O3

all: library

.PHONY: library objs

library: objs
	$(CC) -shared -Wl,-soname,libdanh.so danh.o math.o types.o -o libdanh.so -lc

objs:
	$(CC) $(CFLAGS) -fPIC -c danh.c
	$(CC) $(CFLAGS) -fPIC -c math.c
	$(CC) $(CFLAGS) -fPIC -c types.c
