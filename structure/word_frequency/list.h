// 2021/7/8
// zhangzhong
// list.h

#ifndef _LIST_H_
#define _LIST_H_

#include <stdbool.h>

typedef struct list_node_type
{
    char* word;
    int frequency;
    struct list_node_type* next;
} list_t, list_node_t;

// make an empty single list with a head
list_t* make_list();

bool insert_list(list_t* head, char* word, int frequency);

// print a list
void print_list(list_t* head);

// free a list
void free_list(list_t* head);

#endif // _LIST_H_

