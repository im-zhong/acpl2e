// 2021/6/1
// zhangzhong
// vector

#include "vector.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void realloc_vector(vector_t v)
{
    if (v == NULL)
        return;
    
    if (v->capacity == 0)
        v->capacity = 4;

    v->capacity <<= 1;
    v->data = (char*)realloc(v->data, v->capacity);
}

vector_t make_vector()
{
    vector_t v = (vector_t)malloc(sizeof(struct __vector));
    v->data = NULL;
    v->size = 0;
    v->capacity = 0;
}

void push_back(vector_t v, char c)
{
    if (v == NULL)
        return;

    if (v->size + 1 > v->capacity)
        realloc_vector(v);

    (v->data)[v->size] = c;
    ++(v->size);
}

char pop_back(vector_t v)
{
    if (v == NULL)
        return EOF;
    if (v->data == NULL && v->size == 0)
        return EOF;

    char c = (v->data)[v->size - 1];
    --(v->size);
    return c;
}

void free_vector(vector_t v)
{
    if (v == NULL) 
        return;

    free(v->data);
    free(v);
}

void clear_vector(vector_t v)
{
    v->size = 0;
}

char get_back(vector_t v)
{ 
    if (v == NULL)
        return EOF;
    if (v->data == NULL && v->size == 0)
        return EOF;

    return (v->data)[v->size - 1];
}

char get_front(vector_t v)
{
    if (v == NULL)
        return EOF;
    if (v->data == NULL && v->size == 0)
        return EOF;

    return (v->data)[0];
}

vector_t copy_vector(vector_t v)
{
    if (v == NULL)    
        return NULL;

    vector_t vector = make_vector();
    vector->data = (char*)malloc(v->capacity);
    strncpy(vector->data, v->data, v->size);
    vector->size = v->size;
    vector->capacity = v->capacity;
}
