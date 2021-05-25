// 2021/5/25
// zhangzhong
// Exercise 1-12. Write a program that prints its input one word per line

#include <stdio.h>

#define IN_WORD     (1)
#define OUT_WORD    (0) 

int main()
{
    int c = EOF;
    int state = OUT_WORD; 
        
    while ((c = getchar()) != EOF)
    {
        if (c == ' ' || c == '\t' || c == '\n') 
        {
            if (state == IN_WORD)
            {
                putchar('\n');
                state = OUT_WORD;
            }
        }
        else
        {
            putchar(c);
            if (state == OUT_WORD)
            {
                state = IN_WORD;
            }
        }
    }

    return 0;
}
