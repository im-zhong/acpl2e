// 2021/6/1
// zhangzhong
// Exercise 1-20. Write a program 'detab' that replaces tabs in the input
//                with the proper number of blanks to space to the next
//                tab stops.

#include "vector.h"
#include <stdio.h>

#define TAB_STOP (2)

size_t my_getline(vector_t line)
{
    clear_vector(line);
    int c = EOF;
    while ((c = getchar()) != EOF && c != '\n')
    {
        if (c == '\t')
        {
            for (int i = 0; i < TAB_STOP; ++i)
                push_back(line, ' ');
        }
        else
        {
            push_back(line, c);
        }
    }

    if (c == '\n')
        push_back(line, '\n');
    return line->size;
}

int main(int argc, char* argv[])
{
    vector_t line = make_vector();

    while (my_getline(line) > 0)     
    {
        push_back(line, '\0');
        printf("%s", line->data);
    }
}
