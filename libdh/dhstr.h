/***************************************************************
 * file:	include/dhstr.h
 *************************************************************** */

#ifndef DHSTR_H
#define DHSTR_H

int strlen_dh(char *s);
int strcmp_dh(char *s1, char *s2);
double sdecrep_to_fd_dh(char *s);
long double sdecrep_to_fld_dh(char *s);
int shexrep_to_i_dh(char* s);
long shexrep_to_li_dh(char* s);
int snumrep_to_i_dh(char *s);
unsigned long sbinrep_to_ul_dh(char *s);
int s_is_num_dh(char* s);
int s_is_float_dh(char* s);
int s_is_hex_dh(char *s);
int s_is_n_dh(char *s);
int s_is_z_dh(char *s);
int e2fsck_strnlen(const char * s, int count);

#endif

