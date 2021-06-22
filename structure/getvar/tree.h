// 2021/6/22
// zhangzhong
// tree.h

#ifndef _TREE_H_
#define _TREE_H_

#include "list.h"
#include <stddef.h>

typedef struct tree_node_t {
    list_t* list;
    struct tree_node_t* left;
    struct tree_node_t* right;
} tree_t;

tree_t* make_tree();
tree_t* insert_tree(tree_t* tree, const char* value, size_t prefix_length);
void free_tree(tree_t* tree);
void print_tree(tree_t* tree);

#endif // _TREE_H_

