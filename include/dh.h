/***************************************************************
 * file:	include/dh.h
 *************************************************************** */

#define LIBDH
#define LIBDH_VERSION_MAJOR 0
#define LIBDH_RELEASE 9
#define LIBDH_REVISION 20110514

extern const int dh_version;
extern const int dh_release;
extern const int dh_rev;

extern int strlen_dh(char *s);

extern int strcmp_dh(char *s1, char *s2);

extern void print_ui_to_sbinrep_dh(unsigned int a);

