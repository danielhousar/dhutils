/***************************************************************
 * file:	include/dhstr.h
 *************************************************************** */

#ifndef DHSTR_H
#define DHSTR_H

extern double sdecrep_to_fd_dh(char *s);

extern long double sdecrep_to_fld_dh(char *s);

extern int shexrep_to_i_dh(char* s);

extern long shexrep_to_li_dh(char* s);

extern int snumrep_to_i_dh(char *s);

unsigned int sbinrep_to_ui_dh(char *s);

extern int s_is_num_dh(char* s);

extern int s_is_hex_dh(char *s);

extern int e2fsck_strnlen(const char * s, int count);

#endif

