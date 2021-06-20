// 2021/6/20
// zhangzhong
// 5.5 Character Pointers and Functions
// Exercise 5-3. Write a pointer version of the function strcat.

#include <stdio.h>
#include <stdlib.h>

char* my_strcat(char* dest, const char* src)
{
    char* pdest = dest;
    while (*pdest++);
    --pdest;
    while (*pdest++ = *src++);
    return dest;
}

int main(int argc, char* argv[])
{
    if (argc < 3)
    {
        printf("Usage: %s <dest> <src>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    printf("%s\n", my_strcat(argv[1], argv[2]));
    exit(EXIT_SUCCESS);
}
