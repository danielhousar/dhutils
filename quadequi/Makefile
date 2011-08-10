########################################
# file:	quadequi/Makefile
########################################

include ../MCONFIG

all: binary

.PHONY: binary

binary:
	$(E) "	CCLD quadequi"
	$(Q) $(CC) $(CFLAGS) $(DEFS) main.c -o $(UBIN-OUTDIR)/quadequi -L$(LIB-OUTDIR) -ldh

