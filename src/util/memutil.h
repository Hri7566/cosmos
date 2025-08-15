#ifndef _COSMOS_MEMUTIL_H
#define _COSMOS_MEMUTIL_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

typedef struct Block {
    uint64_t size;
    size_t data;
    Block *next;
} Block;

static Block _memutil_block_head = { 0, 0 };
static const size_t overhead = sizeof(size_t);
static const size_t align_to = 16;

void *memcpy(void *dest, const void *src, size_t n);
void *memset(void *s, int c, size_t n);
void *memmove(void *dest, const void *src, size_t n);
int memcmp(const void *s1, const void *s2, size_t n);

void *malloc(size_t n);
void free(void *src);
Block *memutil_find_block_tail(void);

#endif
