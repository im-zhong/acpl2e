// 2021/6/22
// zhangzhong
// tree.c

#include "tree.h"
#include <stdlib.h>
#include <string.h>

tree_t* make_tree()
{
    // T* pT = (T*)malloc(sizeof(T));
    tree_t* tree = (tree_t*)malloc(sizeof(tree_t));
    tree->list = NULL;
    tree->left = NULL;
    tree->right = NULL;
    return tree;
}

tree_t* insert_tree(tree_t* tree, const char* value, size_t prefix_length)
{
    if (tree == NULL)        
        tree = make_tree();

    if (tree->list == NULL)
    {
        tree->list = make_list();
        tree->list->value = strndup(value, prefix_length);
        insert_list(tree->list, value + (prefix_length < strlen(value) ? prefix_length : strlen(value)));
    }
    else
    {
        int r = strncmp(value, tree->list->value, prefix_length);
        if (r < 0)
            tree->left = insert_tree(tree->left, value, prefix_length);
        else if (r > 0)
            tree->right = insert_tree(tree->right, value, prefix_length);
        else
            insert_list(tree->list, value + (prefix_length < strlen(value) ? prefix_length : strlen(value)));
    }
    return tree;
}

void print_tree(tree_t* tree)
{
    if (tree)
    {
        print_tree(tree->left);
        print_list(tree->list);
        print_tree(tree->right);
    }
}

void free_tree(tree_t* tree)
{
    if (tree) 
    {
        free_tree(tree->left);
        free_tree(tree->right);
        free_list(tree->list);
        free(tree);
    }
}

