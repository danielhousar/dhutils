
DESTDIR=
PREFIX=/usr
BINDIR=$(PREFIX)/bin
LIBDIR=$(PREFIX)/lib
INCLUDEDIR=$(PREFIX)/include
SYSCONFDIR=/etc

CC=gcc
CFLAGS=-march=native -mtune=native -O3

SUBDIRS=libdanh quadequi

all: subdirs

.PHONY: subdirs $(SUBDIRS)

subdirs: $(SUBDIRS)

$(SUBDIRS):
	$(MAKE) -C $@

quadequi: libdanh

.PHONY: clean install uninstall

clean:
	rm -f ./*/*.o
	rm -f bin/*.so

install:
	mkdir -p $(DESTDIR)$(LIBDIR)/
	cp -a bin/libdanh.so $(DESTDIR)$(LIBDIR)/
	mkdir -p $(DESTDIR)$(LIBDIR)/pkgconfig/
	cp -f libdanh.pc $(DESTDIR)$(LIBDIR)/pkgconfig/
	mkdir -p $(DESTDIR)$(INCLUDEDIR)/libdanh
	cp -f include/danhmath.h $(DESTDIR)$(INCLUDEDIR)/libdanh/
	cp -f include/danh.h $(DESTDIR)$(INCLUDEDIR)/libdanh/
	mkdir -p $(DESTDIR)$(BINDIR)/
	cp -f bin/quadequi $(DESTDIR)$(BINDIR)/