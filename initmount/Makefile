########################################
# file:	initmount/Makefile
########################################

include ../MCONFIG

all: binary

.PHONY: binary

binary:
	$(E) "	CCLD initmount"
	$(Q) $(CC) $(CFLAGS) $(DEFS) main.c -o ../.bin/initmount -L../.lib -ldh

