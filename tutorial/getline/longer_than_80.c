// 2021/6/1
// zhangzhong
// 1.9 Character Arrays
// Exercise 1-17. Write a program to print all input lines than are longer than 80 characters.

#include "vector.h"
#include <stdio.h>

size_t mygetline(vector_t line)
{
    clear_vector(line);
    int c = 0;
    while ((c = getchar()) != EOF && c != '\n')
        push_back(line, c);
    if (c == '\n')
        push_back(line, c);
    push_back(line, '\0');
    return line->size - 1;
}

int main(int argc, char* argv[])
{
    vector_t line = make_vector();
    size_t size = 0;
    while ((size = mygetline(line)) > 0) 
    {
        if (size > 80)
            printf("%s", line->data);
    }
    free_vector(line);
    return 0;
}
