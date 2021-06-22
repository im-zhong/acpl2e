// 2021/6/22
// zhangzhong
// 6.5 Self-referential Structures
// Exercise 6-2. Write a program that reads a C program and prints in alphabetical order
//               each group of variables names that are identical in the first 6 characters,
//               but different somewhere thereafter, Don't count words within strings and
//               comments. Make 6 a parameter that can be set from the command line.

#include "token.h"
#include "tree.h"
#include <stdio.h>
#include <stdlib.h>

#define DEFAULT_PREFIX_LENGTH (6)

int main(int argc, char* argv[])
{
    size_t prefix_length = DEFAULT_PREFIX_LENGTH; 
    if (argc > 1)
        prefix_length = atoi(argv[1]);
   
    char* token = NULL;
    size_t token_size = 0;
    tree_t* tree = make_tree();
    while (get_token(&token, &token_size) != -1)
    {
        if (!is_keyword(token))
            insert_tree(tree, token, prefix_length);
    }
    print_tree(tree);

    free(token);
    free_tree(tree);
    exit(EXIT_SUCCESS);
}

