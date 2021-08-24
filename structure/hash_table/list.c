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
        head->symbol = NULL;
        head->replacement = NULL;
        head->next = NULL;
    }
    return head;
}

static list_node_t* find_list_node(list_t* head, const char* symbol)
{
    if (head && symbol)
    {
        for (list_node_t* work = head->next; work; work = work->next)
        {
            if (strcmp(symbol, work->symbol) == 0)
                return work;
        }
    }
    return NULL; 
}

static list_node_t* insert_after(list_node_t* node, const char* symbol, const char* replacement)
{
    if (node == NULL)
        return NULL;

    list_node_t* new_node = make_node();
    if (new_node != NULL)
    {
        new_node->symbol = strdup(symbol);
        new_node->replacement = strdup(replacement);
        new_node->next = node->next;
        node->next = new_node;
    }
    return new_node;
}

void insert_list(list_t* head, const char* symbol, const char* replacement)
{
    // replacement could be nullptr, if you want to clear some key's value
    if (!head || !symbol)
        return;

    list_node_t* node = find_list_node(head, symbol);
    if (node)
    {
        free(node->replacement);
        node->replacement = strdup(replacement);
    }
    else
    {
        insert_after(head, symbol, replacement); 
    }
}

static void free_node(list_t* node)
{
    free(node->symbol);
    free(node->replacement);
    free(node);
}

void free_list(list_t* head)
{
    if (head != NULL)
    {
        list_node_t* next = head->next;
        while (head)
        {
            next = head->next;
            free_node(head);
            head = next;
        }
    }
}

const char* find_list(list_t* head, const char* symbol)
{
    list_node_t* node = find_list_node(head, symbol); 
    if (node)
        return node->replacement;
    return NULL;
}

static void erase_after(list_t* head)
{
    if (!head || !head->next)
        return;

    list_t* next = head->next;
    head->next = next->next;
    free_node(next);
}

void erase_list(list_t* head, const char* symbol)
{
    if (head == NULL || symbol == NULL)
    {
        return;
    }

    for (; head && head->next; head = head->next)
    {
        if (strcmp(symbol, head->next->symbol) == 0)
            erase_after(head);
    }
}
