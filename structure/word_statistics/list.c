// 2021/7/8
// zhangzhong
// list.h

#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static list_node_t* make_node()
{
    return (list_node_t*)malloc(sizeof(list_node_t));
}

list_t* make_list()
{
    list_t* head = make_node();
    if (head != NULL)
    {
        head->line = -1;
        head->next = NULL;
    }
    return head;
}

static list_node_t* insert_after(list_node_t* node, int line)
{
    if (node == NULL)
        return NULL;

    list_node_t* new_node = make_node();
    if (new_node != NULL)
    {
        new_node->line = line;
        new_node->next = node->next;
        node->next = new_node;
    }
    return new_node;
}

bool insert_list(list_t* head, int line)
{
    if (head == NULL)
        return false;

    list_node_t* work = head; 
    while (work->next != NULL)
    {
        if (line < work->next->line)
            break;
        else if (line > work->next->line)
            work = work->next;
        else
            return true;
    }
    return insert_after(work, line) != NULL ? true : false;
}

void print_list(list_t* head)
{
    if (head != NULL)
    {
        head = head->next;
        while (head != NULL)
        {
            printf("%d", head->line);
            if ((head = head->next) != NULL) 
                printf(", ");
        }
    }
    printf("\n");
}

void free_list(list_t* head)
{
    list_node_t* next = head->next;
    while (head)
    {
        next = head->next;
        free(head);
        head = next;
    }
}

