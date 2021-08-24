// 2021/7/8
// zhangzhong
// list.h

#ifndef _LIST_H_
#define _LIST_H_

#include <stdbool.h>

typedef struct list_node_type
{
    char* symbol;
    char* replacement;
    struct list_node_type* next;
} list_t, list_node_t;

// make an empty single list with a head
list_t* make_list();

void insert_list(list_t* head, const char* symbol, const char* replacement);

const char* find_list(list_t* head, const char* symbol);

void erase_list(list_t* head, const char* symbol);

// free a list
void free_list(list_t* head);

#endif // _LIST_H_

