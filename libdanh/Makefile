########################################################
# file:	libdanh/Makefile
########################################################

CC=gcc
CFLAGS=-march=native -mtune=native -O3 -Wall

all: library

.PHONY: library objs

library: objs
	$(CC) -shared -Wl,-soname,libdanh.so ../.out/danh.o ../.out/math.o ../.out/types.o -o ../.lib/libdanh.so -lc

objs:
	$(CC) $(CFLAGS) -fPIC -c danh.c -o ../.out/danh.o
	$(CC) $(CFLAGS) -fPIC -c math.c -o ../.out/math.o
	$(CC) $(CFLAGS) -fPIC -c types.c -o ../.out/types.o
