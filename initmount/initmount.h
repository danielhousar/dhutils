/*****************************************************************************
 * file:	initmount/initmount.h
 ***************************************************************************** */

#ifndef DHIM_H
#define DHIM_H

#ifndef MS_RELATIME
#define MS_RELATIME	0x200000
#endif

const char *im_version_str = "0.1";

/* mount(2) options */
struct mountargs {
       const char *spec;
       const char *node;
       const char *type;
       int flags;
       void *data;
};

#endif

