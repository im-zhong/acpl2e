// 2021/6/1
// zhangzhong
// 1.9 Character Arrays
// Exercise 1-19. Write a function reverse(s) that reverses the character string s.
//                Use it to wirte a program that reverses its input a line at a time.

#include "vector.h"
#include <stdio.h>

void reverse(char* data, size_t size)
{
    if (data == NULL || size == 0) 
        return;

    size_t low = 0;
    size_t high = size - 1;
    char c = EOF;
    while (low < high)
    {
        c = data[low];
        data[low] = data[high];
        data[high] = c;
        ++low;
        --high;
    }
}

size_t my_getline(vector_t line)
{
    clear_vector(line);
    int c = EOF;
    while((c = getchar()) != EOF && c != '\n')
        push_back(line, c);
    if (c == '\n')
        push_back(line, '\n');
    return line->size;
}

int main(int argc, char* argv[])
{
    vector_t line = make_vector(); 
    while (my_getline(line) > 0)
    {
        pop_back(line);
        reverse(line->data, line->size);
        push_back(line, '\n');
        push_back(line, '\0');
        printf("%s", line->data);
    }
    free_vector(line);

    return 0;
}


