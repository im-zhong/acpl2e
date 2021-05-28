// 2021/5/27
// zhangzhong
// string

#include "c_string.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


void init_string(string* src)
{
    if (src == NULL)
        return;

    src->data = NULL;
    src->size = 0;
}

void alloc_string(string* src, const char ch, size_t size)
{
    if (src == NULL || size == 0)
        return;
    
    src->size = size;
    src->data = (char*)malloc(size);
    memset(src->data, ch, size);
}

void copy_string(string* dest, char* src, size_t size)
{
    if (dest == NULL || src == NULL || size == 0)
        return;

    dest->size = size;
    dest->data = (char*)malloc(size);
    strncpy(dest->data, src, size);
}

void free_string(string* src)
{
    if (src == NULL)
        return;

    free(src->data);
    src->data = NULL;
    src->size = 0;
}

void int_to_string(int n, string* str)
{
    char buffer[64];
    int size = snprintf(buffer, 64, "%d", n);
    copy_string(str, buffer, size);
}

int print_string(string str)
{
    if (str.data == NULL || str.size == 0)
        return 0;

    for (size_t i = 0; i < str.size; ++i)
    {
        putchar(str.data[i]);
    }
    return str.size;
}
