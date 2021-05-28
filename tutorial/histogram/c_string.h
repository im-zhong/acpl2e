// 2021/5/27
// zhangzhong
// string

#ifndef __C_STRING_H__
#define __C_STRING_H__

#include <sys/types.h>

typedef struct __string
{
    char* data;
    size_t size;
} string;

void init_string(string* src);

void alloc_string(string* src, const char ch, size_t size);

void copy_string(string* dest, char* src, size_t size);

void free_string(string* src);

void int_to_string(int n, string* str);

int print_string(string str);


#endif // __C_STRING_H__