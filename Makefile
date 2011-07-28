
include ./MCONFIG

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
	cp -a .lib/libdh.so $(DESTDIR)$(LIBDIR)/

install_headers:
	mkdir -p $(DESTDIR)$(INCLUDEDIR)/libdh
	cp -f include/* $(DESTDIR)$(INCLUDEDIR)/libdh/

install_utils:
	mkdir -p $(DESTDIR)$(BINDIR)/
	cp -f .bin/* $(DESTDIR)$(BINDIR)/
	cp -f .bin/initmount $DESTDIR/bin/


uninstall:
	rm -f $(DESTDIR)$(LIBDIR)/libdh.so
	rm -rf $(DESTDIR)$(INCLUDEDIR)/libdh
	rm -f $(DESTDIR)$(BINDIR)/datatypes
	rm -f $(DESTDIR)$(BINDIR)/quadequi
	rm -f $(DESTDIR)$(BINDIR)/portping

