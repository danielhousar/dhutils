
all: binary

.PHONY: binary objs

binary: objs
	$(CC) main.o -o ../bin/quadequi -L../bin -ldanh

objs:
	$(CC) $(CFLAGS) -c main.c
