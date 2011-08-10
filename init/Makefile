########################################
# file:	initmount/Makefile
########################################

include ../MCONFIG

all: binary

.PHONY: binary

binary:
	$(E) "	CC init.o"
	$(Q) $(CC) $(INITCFLAGS) $(INITDEFS) -fPIC -c init.c -o $(OBJ-OUTDIR)/init.o
	$(E) "	CC utmp.o"
	$(Q) $(CC) $(INITCFLAGS) $(INITDEFS) -fPIC -c utmp.c -o $(OBJ-OUTDIR)/utmp.o
	$(E) "	LD init"
	$(Q) $(CC) $(INITOBJS) -o $(BIN-OUTDIR)/dhinit -lc

