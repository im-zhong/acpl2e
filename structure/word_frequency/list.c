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
        head->word = NULL;
        head->frequency = -1;
        head->next = NULL;
    }
    return head;
}

static list_node_t* insert_after(list_node_t* node, char* word, int frequency)
{
    if (node == NULL)
        return NULL;

    list_node_t* new_node = make_node();
    if (new_node != NULL)
    {
        new_node->word = strdup(word);
        new_node->frequency = frequency;
        new_node->next = node->next;
        node->next = new_node;
    }
    return new_node;
}

bool insert_list(list_t* head, char* word, int frequency)
{
    if (head == NULL)
        return false;

    list_node_t* work = head; 
    while (work->next != NULL)
    {
        if (frequency > work->next->frequency)
            break;
        else if (frequency < work->next->frequency)
            work = work->next;
        else
        {
            int r = strcmp(word, work->next->word);
            if (r < 0)
                break;
            else if (r > 0)
                work = work->next;
            else
                return true;
        }
    }
    return insert_after(work, word, frequency) != NULL ? true : false;
}

void print_list(list_t* head)
{
    if (head != NULL)
    {
        head = head->next;
        while (head != NULL)
        {
            printf("%s: %d\n", head->word, head->frequency);
            head = head->next;
        }
    }
}

void free_list(list_t* head)
{
    list_node_t* next = head->next;
    while (head)
    {
        next = head->next;
        free(head->word);
        free(head);
        head = next;
    }
}

