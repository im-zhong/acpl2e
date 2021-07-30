// 2021/7/6
// zhangzhong
// 6.5 Self-referential Structures
// Exercise 6-4. Write a program that prints the distinct words in its input sorted into
//               decreasing order of frequency of occurrence. Precede each word by its
//               count.

#include "getword.h"
#include "list.h"
#include "tree.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    tree_t* tree = make_tree();

    char* word = NULL;
    size_t size = 0;
    while (getword(&word, &size) != EOF)
        insert_tree(tree, word); 

    list_t* list = make_list();
    traverse_tree(tree, list);
    print_list(list);

    free_list(list);
    free_tree(tree);
    free(word);
    exit(EXIT_SUCCESS);
}
