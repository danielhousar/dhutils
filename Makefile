
DESTDIR=
PREFIX=/usr
BINDIR=$(PREFIX)/bin
LIBDIR=$(PREFIX)/lib
INCLUDEDIR=$(PREFIX)/include
SYSCONFDIR=/etc

SUBDIRS=libdanh test quadequi datatypes

all: subdirs

.PHONY: subdirs $(SUBDIRS)

subdirs: $(SUBDIRS)

$(SUBDIRS):
	$(MAKE) -C $@

quadequi: libdanh

.PHONY: clean install uninstall

clean:
	rm -f */*.o
	rm -f libdanh/*.so
	rm -f bin/*
	

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
