// 2021/6/1
// zhangzhong
// 1.9 Character Arrays
// Exercise 1-18. Write a program to remove trailing blanks and tabs from each line of input,
//                and to delete entirely blank lines.

#include "vector.h"
#include <stdio.h>

size_t my_getline(vector_t line)
{
    clear_vector(line);
    int c = EOF;
    while((c = getchar()) != EOF && c != '\n')
        push_back(line, c);
    if (c == '\n')
        push_back(line, c);
    return line->size;
}

void trail(vector_t line)
{
    char back = get_back(line);
    if (back == '\n')
        back = pop_back(line);
    
    for (size_t i = line->size - 1; i >= 0; --i)
    {
        if ((line->data)[i] == ' ' || (line->data)[i] == '\t')       
            pop_back(line);
        else
            break;
    }

    if (back == '\n')
        push_back(line, back);          
}

void replace_space(vector_t line, char c)
{
    for (size_t i = 0; i < line->size; ++i)
    {
        if ((line->data)[i] == ' ' || (line->data)[i] == '\t')
            (line->data)[i] = c;
    }
}


int main(int argc, char* argv[])
{
    vector_t line = make_vector();
    while (my_getline(line) > 0)
    {
        vector_t tmp_line = copy_vector(line);
        replace_space(tmp_line, '*');
        push_back(tmp_line, '\0');
        printf("%s", tmp_line->data);
        pop_back(tmp_line);
        free_vector(tmp_line);
        
        trail(line);
        replace_space(line, '*');
        push_back(line, '\0');
        printf("%s", line->data);
    }

    free_vector(line);
    return 0;
}

