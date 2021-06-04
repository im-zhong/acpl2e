// 2021/6/4
// zhangzhong
// 2.8 Increment and Decrement Operators
// Exercise 2-4. Write an alternative version of squeeze(s1, s2) that deletes
//               each character in s1 that matches any character in s2.

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

// delete all c in s2 from s1
void squeeze(char s1[], char s2[])
{
    int j = 0;
    for (int i = 0; s1[i] != '\0'; ++i)
    {
        if (!contain(s2, s1[i]))
            s1[j++] = s1[i];
    }
    s1[j] = '\0';
}

int main(int argc, char* argv[])
{
    if (argc < 3) 
    {
        printf("Usage: %s <s1> <s2>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    squeeze(argv[1], argv[2]);
    printf("%s", argv[1]);
    exit(EXIT_SUCCESS);
}
