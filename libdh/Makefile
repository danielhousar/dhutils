########################################################
# file:	libdh/Makefile
########################################################

include ../MCONFIG

all: library

.PHONY: library libobj $(LIBDHPARTS)

library: libobj $(LIBDHPARTS)
	$(E) "	LD libdh.so"
	$(Q) $(CC) -shared -Wl,-soname,libdh.so ../.out/dh.o $(LIBDHOBJS) -o ../.lib/libdh.so -lc

$(LIBDHPARTS):
	$(E) "	CC $@.o"
	$(Q) $(CC) $(CFLAGS) $(LIBDEFS) -fPIC -c $@.c -o $(OUTOBJDIR)/$@.o

libobj:
	$(E) "	CC dh.o"
	$(Q) $(CC) $(CFLAGS) $(LIBDEFS) -fPIC -c dh.c -o $(OUTOBJDIR)/dh.o

