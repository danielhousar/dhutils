CC=gcc
CFLAGS=-O2
DEFS= -D UNICODE

all: app

.PHONY: app clean

app:
	$(CC) $(CFLAGS) $(DEFS) main.c -o win-name.exe -lgdi32

clean:
	del win-name.exe

