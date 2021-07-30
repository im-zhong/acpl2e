// 2021/7/6
// zhangzhong
// tree.h

#ifndef _TREE_H_
#define _TREE_H_

#include "list.h"
#include <stddef.h>

typedef struct tree_node_type
{
    char* word;
    int frequency;
    struct tree_node_type* left;
    struct tree_node_type* right;
} tree_node_t;

typedef struct tree_type
{
    tree_node_t* root;
} tree_t;

tree_t* make_tree();

void insert_tree(tree_t* tree, char* word);

void traverse_tree(tree_t* tree, list_t* list);

void free_tree(tree_t* tree);

#endif // _TREE_H_

