########################################
# file:	initmount/Makefile
########################################

include ../MCONFIG

all: dir binary

.PHONY: dir binary

dir:
	mkdir -p $(OBJ-OUTDIR)/dhcalc

binary:
	$(E) "	CC main.o"
	$(Q) $(CC) $(OPT_CFLAGS) $(DEFS) -fPIC -c main.c -o $(OBJ-OUTDIR)/dhcalc/main.o
	$(E) "	LD dhcalc"
	$(Q) $(CC) $(DHCALC_OBJS) -o $(TESTBIN-OUTDIR)/dhcalc -ldh -lm

