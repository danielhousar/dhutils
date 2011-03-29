
DESTDIR=
PREFIX=/usr
BINDIR=$(PREFIX)/bin
LIBDIR=$(PREFIX)/lib
INCLUDEDIR=$(PREFIX)/include
SYSCONFDIR=/etc

SUBDIRS=libdanh test quadequi datatypes

all: bindir $(SUBDIRS)

.PHONY: bindir $(SUBDIRS) clean install uninstall

bindir:
	mkdir -p bin/


$(SUBDIRS):
	$(MAKE) -C $@


clean:
	rm -f */*.o
	rm -f libdanh/*.so
	rm -rf bin/
	

install:
	mkdir -p $(DESTDIR)$(LIBDIR)/
	cp -a libdanh/libdanh.so $(DESTDIR)$(LIBDIR)/
	mkdir -p $(DESTDIR)$(LIBDIR)/pkgconfig/
	cp -f libdanh.pc $(DESTDIR)$(LIBDIR)/pkgconfig/
	mkdir -p $(DESTDIR)$(INCLUDEDIR)/libdanh
	cp -f include/* $(DESTDIR)$(INCLUDEDIR)/libdanh/
	mkdir -p $(DESTDIR)$(BINDIR)/
	cp -f bin/* $(DESTDIR)$(BINDIR)/


uninstall:
	rm -f $(DESTDIR)$(LIBDIR)/libdanh.so
	rm -f $(DESTDIR)$(LIBDIR)/pkgconfig/libdanh.pc
	rm -rf $(DESTDIR)$(INCLUDEDIR)/libdanh
	rm -f $(DESTDIR)$(BINDIR)/datatypes
	rm -f $(DESTDIR)$(BINDIR)/quadequi
