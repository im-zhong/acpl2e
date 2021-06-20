// 2021/6/18
// zhangzhong
// 5.2 Pointers and Function Arguments
// Exercise 5-1. As written, getint treats a + or - not followed by a digit
//               as a valid representation of zero. Fix it to push such a 
//               character back on the input.

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// getint: get next integer from input into *pn
int getint(int *pn)
{
    int c = EOF;
    while(isspace(c = getchar()));

    if (c != EOF && !isdigit(c) && c != '+' && c != '-')
    {
        ungetc(c, stdin);
        return 0;
    }

    int sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-')  
    {
        char signc = c;
        c = getchar();
        if (!isdigit(c))
        {
            ungetc(c, stdin);
            ungetc(signc, stdin);
            return 0;
        }
    }

    for (*pn = 0; isdigit(c); c = getchar())
        *pn = *pn * 10 + (c - '0');
    *pn *= sign;

    if (c != EOF)
        ungetc(c, stdin);

    return c;
}

int main(int argc, char* argv[])
{
    // If there are fewer initializers for
    // an array than the specified size
    // the others will be zero for 
    // external, static and automatic variables
    int array[4096] = {};
    int i = 0;
    for (; i < 4096; ++i)
        if (getint(&array[i]) == EOF)
            break;

    for (int j = 0; j < i; ++j)
        printf("%d\n", array[j]);

    exit(EXIT_SUCCESS);
}
