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

tree_node_t* insert_impl(tree_node_t* node, char* word)
{
    if (node == NULL)
    {
        node = make_node();
        if (node != NULL)
        {
            node->word = strdup(word);
            node->frequency = 1;
            node->left = NULL;
            node->right = NULL;
        }
    }
    else
    {
        int r = strcmp(word, node->word);
        if (r < 0)
            node->left = insert_impl(node->left, word);
        else if (r > 0)
            node->right = insert_impl(node->right, word);
        else
            node->frequency++;
    }
    return node;
}

void insert_tree(tree_t* tree, char* word)
{
    if (tree == NULL || word == NULL)
        return;
    tree->root = insert_impl(tree->root, word);
}

static void traverse_tree_impl(tree_node_t* node, list_t* list)
{
    if (node == NULL)
        return;

    traverse_tree_impl(node->left, list);
    insert_list(list, node->word, node->frequency);
    traverse_tree_impl(node->right, list);
}

void traverse_tree(tree_t* tree, list_t* list)
{
    if (tree == NULL || list == NULL) 
        return;

    traverse_tree_impl(tree->root, list); 
}

static void free_node(tree_node_t* node)
{
    if (node != NULL)
    {
        free_node(node->left);
        free_node(node->right);

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

