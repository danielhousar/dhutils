CC=gcc
CFLAGS=-O2
DEFS=-D UNICODE

all: app

.PHONY: app obj res clean

app: obj res
	$(CC) window.res main.o -o window.exe -lgdi32 -mwindows

obj:
	$(CC) $(CFLAGS) $(DEFS) -c main.c -o main.o -Wall

res:
	windres -i window.rc --input-format=rc -o window.res -O coff

clean:
	del main.o
	del window.res
	del window.exe

