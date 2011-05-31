########################################
# file:	portping/Makefile
########################################

include ../MCONFIG

all: binary

.PHONY: binary

binary:
	$(CC) $(CFLAGS) $(DEFS) main.c -o ../.bin/portping -L../.lib -ldh

