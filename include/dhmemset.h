/***************************************************************
 * file:	include/dhmemset.h
 *
 * Author:	Matthew Fernandez (matthew.fernandez@gmail.com)
 *
 *************************************************************** */

#ifndef DHMEMSET_H
#define DHMEMSET_H

#include <stdio.h>
#include <stdint.h>
#include <assert.h>

typedef unsigned char byte;

extern void* bytewise_memset(void* s, int c, size_t sz);

extern void* wordwise_32_memset(void* s, int c, size_t sz);

extern void* wordwise_32_unaligned_memset(void* s, int c, size_t sz);

#ifdef __WORDSIZE
extern void* wordwise_memset(void* s, int c, size_t sz);
extern void* wordwise_unaligned_memset(void* s, int c, size_t sz);
#endif

void* duffs_device_memset(void* s, int c, size_t sz);

#endif

