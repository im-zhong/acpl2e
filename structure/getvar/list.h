// 2021/6/22
// zhangzhong
// list.h

#ifndef _LIST_H_
#define _LIST_H_

typedef struct list_node_t {
    char* value;
    struct list_node_t* next;
} list_t;

list_t* make_list();
void insert_list(list_t* list, const char* value);
void free_list(list_t* list);
void print_list(list_t* list);

#endif // _LIST_H_
