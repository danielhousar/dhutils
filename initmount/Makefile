########################################
# file:	initmount/Makefile
########################################

include ../MCONFIG

IMOBJS=../.out/initmount.o

all: binary

.PHONY: binary

binary:
	$(E) "	CC initmount.o"
	$(Q) $(CC) $(CFLAGS) $(DEFS) -fPIC -c main.c -o ../.out/initmount.o
	$(E) "	LD initmount"
	$(Q) $(CC) $(CFLAGS) $(DEFS) $(IMOBJS) -o ../.bin/initmount -lc

