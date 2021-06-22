// 2021/6/22
// zhangzhong
// list.c

#include "list.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

list_t* make_list()
{
    list_t* list = (list_t*)malloc(sizeof(list_t));
    list->value = NULL;
    list->next = NULL;
    return list;
}

static list_t* make_node(const char* value, list_t* next)
{
    list_t* list = (list_t*)malloc(sizeof(list_t));
    list->value = strdup(value);
    list->next = next; 
    return list;
}

static list_t* insert_after(list_t* list, const char* value)
{
    if (list == NULL || value == NULL)
        return NULL;

    list_t* node = make_node(value, list->next);
    list->next = node;
    return node;
}

void insert_list(list_t* list, const char* value)
{
    if (list == NULL || value == NULL)
        return;

    list_t* work = list;
    while (work->next)
    {
        int r = strcmp(value, work->next->value);
        if (r == 0)
            return;
        if (r < 0)
            break;
        work = work->next;
    }
    insert_after(work, value);
}

void free_list(list_t* list)
{
    list_t* work = list;
    list_t* next = NULL;
    while (work)
    {
        next = work->next;
        free(work->value);
        free(work);
        work = next;
    }
}

void print_list(list_t* list)
{
    const char* prefix = list ? list->value : "";
    while (list->next)    
    {
        printf("%s%s", prefix, list->next->value);
        list = list->next;
        if (list->next)
            printf(", ");
    }
    printf("\n");
}

