
DESTDIR=
PREFIX=/usr
BINDIR=$(PREFIX)/bin
LIBDIR=$(PREFIX)/lib
INCLUDEDIR=$(PREFIX)/include
SYSCONFDIR=/etc

SUBDIRS=libdanh quadequi datatypes

all: outdirs $(SUBDIRS)

.PHONY: outdirs $(SUBDIRS) clean install install_lib install_headers install_utils uninstall

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


install: install_lib install_headers install_utils

install_lib:
	mkdir -p $(DESTDIR)$(LIBDIR)/
	cp -a .lib/libdanh.so $(DESTDIR)$(LIBDIR)/
	mkdir -p $(DESTDIR)$(LIBDIR)/pkgconfig/
	cp -f libdanh.pc $(DESTDIR)$(LIBDIR)/pkgconfig/

install_headers:
	mkdir -p $(DESTDIR)$(INCLUDEDIR)/libdanh
	cp -f include/* $(DESTDIR)$(INCLUDEDIR)/libdanh/

install_utils:
	mkdir -p $(DESTDIR)$(BINDIR)/
	cp -f .bin/* $(DESTDIR)$(BINDIR)/


uninstall:
	rm -f $(DESTDIR)$(LIBDIR)/libdanh.so
	rm -f $(DESTDIR)$(LIBDIR)/pkgconfig/libdanh.pc
	rm -rf $(DESTDIR)$(INCLUDEDIR)/libdanh
	rm -f $(DESTDIR)$(BINDIR)/datatypes
	rm -f $(DESTDIR)$(BINDIR)/quadequi
