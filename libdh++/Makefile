########################################################
# file:	libdh/Makefile
########################################################

include ../MCONFIG

all: dir library

.PHONY: library libobj $(LIBDHPARTS) dir

dir:
	mkdir -p $(OBJ-OUTDIR)/libdh++

library: libobj
	$(E) "	LD libdh$(SOEXT)"
	$(Q) $(CXX) $(SO_CFLAGS) ../.out/libdh++/dh.o -o ../.lib/libdh$(SOEXT) $(SO_LDFLAGS)

$(LIBDHPARTS):
	$(E) "	CXX $@.o"
	$(Q) $(CXX) $(OPT_CFLAGS) $(LIB_CFLAGS) $(LIBDEFS) -c $@.c -o $(OBJ-OUTDIR)/$@.o

libobj:
	$(E) "	CXX dh.o"
	$(Q) $(CXX) $(OPT_CFLAGS) $(LIB_CFLAGS) $(LIBDEFS) -c dh.cpp -o $(OBJ-OUTDIR)/libdh++/dh.o

