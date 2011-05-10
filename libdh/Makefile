########################################################
# file:	libdh/Makefile
########################################################

CC=gcc
CFLAGS=-march=native -mtune=native -O3 -Wall
DEFS=

all: library

.PHONY: library objs

library: objs
	$(CC) -shared -Wl,-soname,libdh.so ../.out/dh.o ../.out/math.o ../.out/types.o ../.out/misc.o -o ../.lib/libdh.so -lc

objs:
	$(CC) $(CFLAGS) $(DEFS) -fPIC -c dh.c -o ../.out/dh.o
	$(CC) $(CFLAGS) $(DEFS) -fPIC -c math.c -o ../.out/math.o
	$(CC) $(CFLAGS) $(DEFS) -fPIC -c types.c -o ../.out/types.o
	$(CC) $(CFLAGS) $(DEFS) -fPIC -c misc.c -o ../.out/misc.o
