########################################################
# file:	libdh/Makefile
########################################################

include ../MCONFIG

all: library

.PHONY: library libobj $(LIBDHPARTS)

library: libobj $(LIBDHPARTS)
	$(CC) -shared -Wl,-soname,libdh.so ../.out/dh.o $(LIBDHOBJS) -o ../.lib/libdh.so -lc

$(LIBDHPARTS):
	$(CC) $(CFLAGS) $(LIBDEFS) -fPIC -c $@.c -o $(OUTOBJDIR)/$@.o

libobj:
	$(CC) $(CFLAGS) $(LIBDEFS) -fPIC -c dh.c -o $(OUTOBJDIR)/dh.o

