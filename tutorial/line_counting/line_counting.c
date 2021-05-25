// 2021/5/25
// zhangzhong
// 1.5.3 Line Counting
// Exercise 1-8: Write a program to count blanks, tabs, and newlines.
// Exercise 1-9: Write a program to copy its input to its output,
//               replacing each string of one or more blanks by a single blank.
// Exercise 1-10: Write a program to copy its input to its output,
//                replacing each tab by \t, each backspace by \b
//                and each backslash by \\. This makes tabs and backspaces visible
//                in an unambiguous way.
// implement by getchar & putchar

#include <stdio.h>

int main()
{
    long blank_count = 0;
    long tab_count = 0;
    long line_count = 0;

    int is_space = 0;
    int c = 0;
    while ((c = getchar()) != EOF)
    {
        if (c == ' ')
        {
            is_space = 1;
            ++blank_count;        
        }
        else
        {
            if (is_space) putchar(' ');
            is_space = 0;

            if (c == '\t')
            {
                ++tab_count; 
                putchar('\\');
                putchar('t');
            }
            else if (c == '\n') 
            {
                ++line_count;
                putchar(c);
            }
            else if (c == '\b')
            {
                putchar('\\');
                putchar('b');
            }
            else if (c == '\\')
            {
                putchar('\\');
                putchar('\\');
            }
            else
            {
                putchar(c);
            }
        }
    }
    
    printf("----------------total----------------\n");
    printf("blank: %ld\n", blank_count);
    printf("tab: %ld\n", tab_count);
    printf("line: %ld\n", line_count);
    
    return 0;
}

