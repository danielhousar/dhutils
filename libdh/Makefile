########################################################
# file:	libdh/Makefile
########################################################

include ../MCONFIG

all: library

.PHONY: library libobj $(LIBDHPARTS)

library: libobj $(LIBDHPARTS)
	$(E) "	LD libdh$(SOEXT)"
	$(Q) $(CC) $(SO_CFLAGS) ../.out/dh.o $(LIBDHOBJS) -o ../.lib/libdh$(SOEXT) $(SO_LDFLAGS)

$(LIBDHPARTS):
	$(E) "	CC $@.o"
	$(Q) $(CC) $(OPT_CFLAGS) $(LIB_CFLAGS) $(LIBDEFS) -c $@.c -o $(OBJ-OUTDIR)/$@.o

libobj:
	$(E) "	CC dh.o"
	$(Q) $(CC) $(OPT_CFLAGS) $(LIB_CFLAGS) $(LIBDEFS) -c dh.c -o $(OBJ-OUTDIR)/dh.o

