// 2021/7/6
// zhangzhong
// tree.c

#include "tree.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

static tree_node_t* make_node()
{
    return (tree_node_t*)malloc(sizeof(tree_node_t));
}

tree_t* make_tree()
{
    tree_t* tree = (tree_t*)malloc(sizeof(tree_t)); 
    if (tree != NULL)
        tree->root = NULL;
    return tree;
}

tree_node_t* insert_impl(tree_node_t* node, char* word, int line)
{
    if (node == NULL)
    {
        node = make_node();
        if (node != NULL)
        {
            node->word = strdup(word);
            node->list = make_list();
            insert_list(node->list, line);
            node->left = NULL;
            node->right = NULL;
        }
    }
    else
    {
        int r = strcmp(word, node->word);
        if (r < 0)
            node->left = insert_impl(node->left, word, line);
        else if (r > 0)
            node->right = insert_impl(node->right, word, line);
        else
            insert_list(node->list, line);
    }
    return node;
}

bool insert_tree(tree_t* tree, char* word, int line)
{
    if (tree == NULL || word == NULL)
        return false;

    // how to judge success or failure
    tree->root = insert_impl(tree->root, word, line);
    return true;
}

static void print_node(tree_node_t* node)
{
    if (node != NULL)
    {
        print_node(node->left);

        printf("%s: ", node->word);
        print_list(node->list);

        print_node(node->right);
    }
}

void print_tree(tree_t* tree)
{
    print_node(tree->root);
}

static void free_node(tree_node_t* node)
{
    if (node != NULL)
    {
        free_node(node->left);
        free_node(node->right);

        free_list(node->list);
        free(node->word);
        free(node);
    }
}

void free_tree(tree_t* tree)
{
    if (tree == NULL)
        return;
    free_node(tree->root);
}

