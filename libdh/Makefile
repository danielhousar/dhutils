########################################################
# file:	libdh/Makefile
########################################################

include ../MCONFIG

all: library

.PHONY: library libobj $(LIBDHPARTS)

library: libobj $(LIBDHPARTS)
	$(E) "	LD libdh$(SOEXT)"
	$(Q) $(CC) -shared -Wl,-soname,libdh$(SOEXT) ../.out/dh.o $(LIBDHOBJS) -o ../.lib/libdh$(SOEXT) $(LIBLDFLAGS)

$(LIBDHPARTS):
	$(E) "	CC $@.o"
	$(Q) $(CC) $(CFLAGS) $(LIBCFLAGS) $(LIBDEFS) -c $@.c -o $(OUTOBJDIR)/$@.o

libobj:
	$(E) "	CC dh.o"
	$(Q) $(CC) $(CFLAGS) $(LIBCFLAGS) $(LIBDEFS) -c dh.c -o $(OUTOBJDIR)/dh.o

