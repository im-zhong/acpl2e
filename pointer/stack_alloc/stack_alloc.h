// 2021/6/20
// zhangzhong
// 5.4 Address Arithmetic
// Stack Allocator

#ifndef _STACK_ALLOC_H_
#define _STACK_ALLOC_H_

#include <stddef.h>

#define HEAP_SIZE (4096)
static char heap[HEAP_SIZE] = {};
static char* sp = heap;

char* stack_alloc(size_t n);
void stack_free(char* p);

#endif // _STACK_ALLOC_H_
