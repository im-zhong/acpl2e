// 2021/6/1
// zhangzhong
// Exercise 1-21. Write a program 'entab' that replaces strings of blanks by the minimum
//                number of tabs and blanks to achieve the same spacing.\
//                When either a tab or a single blank would suffice to reach a tab stop,
//                which should be given preference?

#include "vector.h"
#include <stdio.h>

#define TAB_STOP    (4)
#define IN_SPACE    (1)
#define OUT_SPACE   (0)

size_t my_getline(vector_t line)
{
    clear_vector(line);
    int c = EOF;
    int state = OUT_SPACE;
    int space_count = 0;
    while ((c = getchar()) != EOF && c != '\n')
    {
        if (c == ' ') 
        {
            if (state == OUT_SPACE)
                state = IN_SPACE;

            ++space_count;
            if (space_count == TAB_STOP)
            {
                push_back(line, '\t');
                space_count = 0;
            }
        }
        else
        {
            if (state == IN_SPACE)
            {
                state = OUT_SPACE;
                for (int i = 0; i < space_count; ++i)
                    push_back(line, ' ');
                space_count = 0;
            }
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
    return 0;
}

