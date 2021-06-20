// 2021/6/20 zhangzhong
// 5.4 Address Arithmetic
// Stack Allocator

#include "stack_alloc.h"

char* stack_alloc(size_t n)
{
    if (sp + n - heap <= HEAP_SIZE)
    {
        sp += n;
        return sp - n;
    }
    else
    {
        return NULL;
    }
}

void stack_free(char* p)
{
    if (p >= heap && p < sp)
        sp = p;
}
