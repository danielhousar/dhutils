########################################
# file:	portping/Makefile
########################################

include ../MCONFIG

all: binary

.PHONY: binary

binary:
	$(E) "	CCLD portping"
	$(Q) $(CC) $(CFLAGS) $(DEFS) main.c -o $(UBIN-OUTDIR)/portping -L$(LIB-OUTDIR) -ldh

