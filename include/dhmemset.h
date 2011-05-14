/***************************************************************
 * file:	include/dhmemset.h
 *
 * Author:	Matthew Fernandez (matthew.fernandez@gmail.com)
 *
 *************************************************************** */

#include <stdio.h>
#include <stdint.h>
#include <assert.h>

typedef unsigned char byte;

extern void* bytewise_memset(void* s, int c, size_t sz);

extern void* wordwise_32_memset(void* s, int c, size_t sz);

extern void* wordwise_memset(void* s, int c, size_t sz);

extern void* wordwise_32_unaligned_memset(void* s, int c, size_t sz);

extern void* wordwise_unaligned_memset(void* s, int c, size_t sz);

void* duffs_device_memset(void* s, int c, size_t sz);
