// 2021/5/25
// zhangzhong
// input -> output

#include <stdio.h>

int main()
{
    // in stdio.h
    // extern int getchar();
    // extern int putchar(int);
    // #define EOF (-1)
    // so the c must be declaraed in type 'int'
    int c = 0;
    while ((c = getchar()) != EOF)
    {
        putchar(c);
    }
    return 0;
}
