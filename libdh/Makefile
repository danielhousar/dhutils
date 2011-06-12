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

#math:
#	$(CC) $(CFLAGS) $(LIBDEFS) -fPIC -c math.c -o $(OUTOBJDIR)/math.o

#str:
#	$(CC) $(CFLAGS) $(LIBDEFS) -fPIC -c str.c -o $(OUTOBJDIR)/str.o

#misc:
#	$(CC) $(CFLAGS) $(LIBDEFS) -fPIC -c misc.c -o $(OUTOBJDIR)/misc.o

#memset:
#	$(CC) $(CFLAGS) $(LIBDEFS) -fPIC -c memset.c -o $(OUTOBJDIR)/memset.o

