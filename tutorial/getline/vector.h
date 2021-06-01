// 2021/6/1
// zhangzhong
// vector

#ifndef __VECTOR_H__
#define __VECTOR_H__

#include <sys/types.h>

typedef struct __vector
{
    char* data;
    size_t size;
    size_t capacity;
} *vector_t;

vector_t make_vector();
void push_back(vector_t v, char c);
char pop_back(vector_t v);
void free_vector(vector_t v);
void clear_vector(vector_t v);

char get_back(vector_t v);
char get_front(vector_t v);

vector_t copy_vector(vector_t v);

#endif // __VECTOR_H__
