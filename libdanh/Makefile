
DESTDIR=
PREFIX=/usr
LIBDIR=$(PREFIX)/lib
INCLUDEDIR=$(PREFIX)/include
SYSCONFDIR=/etc

CC=gcc
CFLAGS=-march=native -mtune=native -O3

all: library

library: objs
	$(CC) -shared -Wl,-soname,libdanh.so.0 danh.o math.o -o ../bin/libdanh.so -lc
objs:
	$(CC) $(CFLAGS) -fPIC -c danh.c
	$(CC) $(CFLAGS) -fPIC -c math.c

clean:
	rm -f *.o
	rm -f *.so
	rm -f *.so.0

install: libdanh.so
	mkdir -p $(DESTDIR)$(LIBDIR)/
	cp -a libdanh.so $(DESTDIR)$(LIBDIR)/
	ln -sf libdanh.so libdanh.so.0
	cp -a libdanh.so.0 $(DESTDIR)$(LIBDIR)/
	mkdir -p $(DESTDIR)$(LIBDIR)/pkgconfig/
	cp -f libdanh.pc $(DESTDIR)$(LIBDIR)/pkgconfig/
	mkdir -p $(DESTDIR)$(INCLUDEDIR)/libdanh
	cp -f include/danhmath.h $(DESTDIR)$(INCLUDEDIR)/libdanh/
	cp -f include/danh.h $(DESTDIR)$(INCLUDEDIR)/libdanh/

uninstall:
	rm -f $(LIBDIR)/libdanh.*
	rm -f $(LIBDIR)/pkgconfig/libdanh.pc
	rm -rf $(INCLUDEDIR)/libdanh

