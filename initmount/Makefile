########################################
# file:	initmount/Makefile
########################################

include ../MCONFIG

IMOBJS=../.out/initmount.o

all: binary

.PHONY: binary

binary:
	$(E) "	CC initmount.o"
	$(Q) $(CC) $(OPT_CFLAGS) $(WARN_CFLAGS) $(STD_CFLAGS) $(DEFS) -fPIC -c main.c -o $(OBJ-OUTDIR)/initmount.o
	$(E) "	LD initmount"
	$(Q) $(CC) $(IMOBJS) -o $(SBIN-OUTDIR)/initmount -lc

