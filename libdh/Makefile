########################################################
# file:	libdh/Makefile
########################################################

include ../MCONFIG

all: dir library

.PHONY: dir library libobj $(LIBDHPARTS)

dir:
	mkdir -p $(OBJ-OUTDIR)/libdh

library: libobj $(LIBDHPARTS)
	$(E) "	LD libdh$(SOEXT)"
	$(Q) $(CC) $(SO_CFLAGS) $(WARN_CFLAGS) $(OBJ-OUTDIR)/libdh/dh.o $(LIBDHOBJS) -o $(LIB-OUTDIR)/libdh$(SOEXT) $(SO_LDFLAGS)

$(LIBDHPARTS):
	$(E) "	CC $@.o"
	$(Q) $(CC) $(OPT_CFLAGS) $(LIB_CFLAGS) $(DEFS) -c $@.c -o $(OBJ-OUTDIR)/libdh/$@.o

libobj:
	$(E) "	CC dh.o"
	$(Q) $(CC) $(OPT_CFLAGS) $(LIB_CFLAGS) $(DEFS) -c dh.c -o $(OBJ-OUTDIR)/libdh/dh.o

