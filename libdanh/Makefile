
all: library

.PHONY: library objs

library: objs
	$(CC) -shared -Wl,-soname,libdanh.so.0 danh.o math.o -o ../bin/libdanh.so -lc

objs:
	$(CC) $(CFLAGS) -fPIC -c danh.c
	$(CC) $(CFLAGS) -fPIC -c math.c
