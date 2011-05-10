CC=gcc
CFLAGS=-O2

all: app

.PHONY: app obj res

app: obj res
	$(CC) win32-window.res main.o -o win32-window.exe

obj:
	$(CC) $(CFLAGS) $(DEFS) -c main.c -o main.o -Wall -lgdi32

res:
	windres -i win32-window.rc --input-format=rc -o win32-window.res -O coff
