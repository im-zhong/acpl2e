// 2021/6/16
// zhangzhong
// 4.1 Basics of Functions
// Exercise 4-1. Write the function strindex(s,t) which returns the position of the
//               rightmost occurrence of t in s, or -1 if there is none.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int strindex(const char* s, const char* t)
{
    for (int i = 0; s[i]; ++i)
    {
        int k = 0;
        for (int j = i; s[j] && t[k] && s[j] == t[k]; ++j, ++k);
        // if (k == strlen(t))
        if (k > 0 && t[k] == '\0')
            return i;
    }
    return -1;
}

int reverse_strindex(const char* s, const char* t)
{
    size_t length = strlen(t);
    int j = 0;
    int k = 0;
    for (int i = (int)strlen(s) - 1; i >= 0; --i) 
    {
        for (j = i, k = length - 1; j >= 0 && k >= 0 && s[j] == t[k]; --j, --k);
        if (k < 0)
            return j + 1;
    }
    return -1;
}

int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        printf("Usage: %s <needle>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char* line = NULL;
    size_t line_size = 0;
    ssize_t read_size = 0;
    while ((read_size = getline(&line, &line_size, stdin)) != -1)
    {
        // if (strstr(line, argv[1])) 
        // if (strindex(line, argv[1]) != -1)
        if (reverse_strindex(line, argv[1]) != -1)
            printf("%s", line);
    }

    free(line);
    exit(EXIT_SUCCESS);
}
