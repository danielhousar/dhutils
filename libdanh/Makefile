########################################################
# file:	libdanh/Makefile
########################################################

CC=gcc
CFLAGS=-march=native -mtune=native -O3 -Wall
DEFS=

all: library

.PHONY: library objs

library: objs
	$(CC) -shared -Wl,-soname,libdanh.so ../.out/danh.o ../.out/math.o ../.out/types.o ../.out/misc.o -o ../.lib/libdanh.so -lc

objs:
	$(CC) $(CFLAGS) $(DEFS) -fPIC -c danh.c -o ../.out/danh.o
	$(CC) $(CFLAGS) $(DEFS) -fPIC -c math.c -o ../.out/math.o
	$(CC) $(CFLAGS) $(DEFS) -fPIC -c types.c -o ../.out/types.o
	$(CC) $(CFLAGS) $(DEFS) -fPIC -c misc.c -o ../.out/misc.o
