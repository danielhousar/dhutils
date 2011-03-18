
DESTDIR=
PREFIX=/usr
BINDIR=$(PREFIX)/bin
LIBDIR=$(PREFIX)/lib
INCLUDEDIR=$(PREFIX)/include
SYSCONFDIR=/etc

SUBDIRS=libdanh quadequi sqrt-test

all: subdirs

.PHONY: subdirs $(SUBDIRS)

subdirs: $(SUBDIRS)

$(SUBDIRS):
	$(MAKE) -C $@

quadequi: libdanh

.PHONY: clean install uninstall

clean:
	rm -f */*.o
	rm -f bin/*.so
	rm -f bin/quadequi
	rm -f bin/sqrt-test

install:
	mkdir -p $(DESTDIR)$(LIBDIR)/
	cp -a bin/libdanh.so $(DESTDIR)$(LIBDIR)/
	mkdir -p $(DESTDIR)$(LIBDIR)/pkgconfig/
	cp -f libdanh.pc $(DESTDIR)$(LIBDIR)/pkgconfig/
	mkdir -p $(DESTDIR)$(INCLUDEDIR)/libdanh
	cp -f include/* $(DESTDIR)$(INCLUDEDIR)/libdanh/
	mkdir -p $(DESTDIR)$(BINDIR)/
	cp -f bin/quadequi $(DESTDIR)$(BINDIR)/
	cp -f bin/sqrt-test $(DESTDIR)$(BINDIR)/

uninstall:
	rm -f $(DESTDIR)$(LIBDIR)/libdanh.so
	rm -f $(DESTDIR)$(LIBDIR)/pkgconfig/libdanh.pc
	rm -f $(DESTDIR)$(BINDIR)/quadequi
	rm -rf $(DESTDIR)$(INCLUDEDIR)/libdanh
	rm -f $(DESTDIR)$(BINDIR)/sqrt-test
