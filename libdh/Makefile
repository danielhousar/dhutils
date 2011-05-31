########################################################
# file:	libdh/Makefile
########################################################

include ../MCONFIG

all: library

.PHONY: library objs

library: objs
	$(CC) -shared -Wl,-soname,libdh.so ../.out/dh.o ../.out/math.o ../.out/str.o ../.out/misc.o ../.out/memset.o -o ../.lib/libdh.so -lc

objs:
	$(CC) $(CFLAGS) $(LIBDEFS) -fPIC -c dh.c -o ../.out/dh.o
	$(CC) $(CFLAGS) $(LIBDEFS) -fPIC -c math.c -o ../.out/math.o
	$(CC) $(CFLAGS) $(LIBDEFS) -fPIC -c str.c -o ../.out/str.o
	$(CC) $(CFLAGS) $(LIBDEFS) -fPIC -c misc.c -o ../.out/misc.o
	$(CC) $(CFLAGS) $(LIBDEFS) -fPIC -c linux/memset.c -o ../.out/memset.o
