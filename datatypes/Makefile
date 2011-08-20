########################################
# file:	datatypes/Makefile
########################################

include ../MCONFIG

all: binary

.PHONY: binary

binary:
	$(E) "	CCLD datatypes"
	$(Q) $(CC) $(CFLAGS) $(DEFS) main.c -o $(UBIN-OUTDIR)/datatypes -L$(LIB-OUTDIR) -ldh

