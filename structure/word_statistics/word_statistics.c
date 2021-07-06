// 2021/7/6
// zhangzhong
// 6.5 Self-referential Structures
// Exercise 6-3. Write a cross-referencer that prints a list of all words in a document,
//               and for each word, a list of the line numbers on which it occurs. Remove
//               the noise words like 'the', 'and' and so on.

#include "tree.h"
#include "getword.h"
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char* argv[])
{
    char* word = NULL;
    size_t size = 0;
    int line = 0;
    tree_t* tree = make_tree();

    while (getword(&word, &size, &line) != EOF)
        insert_tree(tree, word, line);
    print_tree(tree);

    free_tree(tree);
    free(word);
    exit(EXIT_SUCCESS);
}
