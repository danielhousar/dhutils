/***************************************************************
 * file:	include/dh.h
 *************************************************************** */

typedef unsigned char byte;

#define CHECK(f, unaligned) \
    do { \
        int fail_byte = check_memset((f), (unaligned)); \
        if (fail_byte) \
            printf("%s %s check failed on byte %d.\n", \
                   (unaligned) ? "Unaligned" : "Aligned", #f, fail_byte - 1); \
    } while(0)

#define BUFFER_LEN 4096

extern void* bytewise_memset(void* s, int c, size_t sz);

extern void* wordwise_32_memset(void* s, int c, size_t sz);

extern void* wordwise_memset(void* s, int c, size_t sz);

extern void* wordwise_32_unaligned_memset(void* s, int c, size_t sz);

extern void* wordwise_unaligned_memset(void* s, int c, size_t sz);

extern int check_memset(void* f(), int unaligned);

extern int test_memset_dh(void);

