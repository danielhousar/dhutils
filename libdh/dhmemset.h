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

 void* bytewise_memset(void* s, int c, size_t sz);
 void* wordwise_32_memset(void* s, int c, size_t sz);
 void* wordwise_32_unaligned_memset(void* s, int c, size_t sz);

#ifdef __WORDSIZE
 void* wordwise_memset(void* s, int c, size_t sz);
 void* wordwise_unaligned_memset(void* s, int c, size_t sz);
#endif

void* duffs_device_memset(void* s, int c, size_t sz);

#endif

