// 2021/6/4
// zhangzhong
// 2.8 Increment and Decrement Operators
// Exercise 2-5. Write the function any(s1, s2), which returns the first location
//               in a string s1 where any character from the string s2 occurs,
//               or -1 if s1 contains no character from s2.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int contain(char s[], char c)
{
    for (; *s; ++s)
        if (*s == c) 
            return 1;
    return 0;
}

int any(char s1[], char s2[])
{
    for (int i = 0; s1[i]; ++i)
    {
        if (contain(s2, s1[i]))
            return i;
    }
    return -1;
}

int any_strpbrk(char s1[], char s2[])
{
    char* p = strpbrk(s1, s2);
    return p ? p - s1 : -1;
}

int main(int argc, char* argv[])
{
    if (argc < 3) 
    {
        printf("Usage: %s <s1> <s2>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    printf("any: %d\n", any(argv[1], argv[2]));
    printf("strpbrk: %d\n", any_strpbrk(argv[1], argv[2]));

    exit(EXIT_SUCCESS);
}

