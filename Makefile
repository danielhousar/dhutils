
DESTDIR=
PREFIX=/usr
BINDIR=$(PREFIX)/bin
LIBDIR=$(PREFIX)/lib
INCLUDEDIR=$(PREFIX)/include
SYSCONFDIR=/etc

SUBDIRS=libdanh test quadequi datatypes

all: outdirs $(SUBDIRS)

.PHONY: outdirs $(SUBDIRS) clean install uninstall

outdirs:
	mkdir -p .bin/
	mkdir -p .lib/
	mkdir -p .out/


$(SUBDIRS):
	$(MAKE) -C $@


clean:
	rm -rf .bin/
	rm -rf .lib/
	rm -rf .out/
	

install:
	mkdir -p $(DESTDIR)$(LIBDIR)/
	cp -a .lib/libdanh.so $(DESTDIR)$(LIBDIR)/
	mkdir -p $(DESTDIR)$(LIBDIR)/pkgconfig/
	cp -f libdanh.pc $(DESTDIR)$(LIBDIR)/pkgconfig/
	mkdir -p $(DESTDIR)$(INCLUDEDIR)/libdanh
	cp -f include/* $(DESTDIR)$(INCLUDEDIR)/libdanh/
	mkdir -p $(DESTDIR)$(BINDIR)/
	cp -f .bin/* $(DESTDIR)$(BINDIR)/


uninstall:
	rm -f $(DESTDIR)$(LIBDIR)/libdanh.so
	rm -f $(DESTDIR)$(LIBDIR)/pkgconfig/libdanh.pc
	rm -rf $(DESTDIR)$(INCLUDEDIR)/libdanh
	rm -f $(DESTDIR)$(BINDIR)/datatypes
	rm -f $(DESTDIR)$(BINDIR)/quadequi
