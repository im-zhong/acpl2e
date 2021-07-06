// 2021/7/6
// zhangzhong
// getword.c

#include "getword.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>

static bool isword(int c)
{
    return isalpha(c);
}

static int line_ = 1;

int getword(char** word, size_t* size, int* line)
{
    if (word == NULL || size == NULL || line == NULL)
        return EOF;

    int c = EOF;
    while ((c = getchar()) != EOF)
    {
        if (c == '\n') 
            ++line_;
        else if (isword(c))
            break;
    }
    if (c == EOF)
        return EOF;

    // if *word == NULL or *size == 0
    // we need allocate memory for it
    if (*word == NULL || *size == 0)
    {
        *size = 64;
        *word = (char*)malloc(sizeof(char) * (*size));
    }

    int i = 0;
    do {
        // remain one bit for '\0'
        if (i >= *size - 1)
            *word = (char*)realloc(*word, *size *= 2);
        (*word)[i++] = c;
    } while (isword(c = getchar()));
    ungetc(c, stdin);

    (*word)[i] = '\0';
    *line = line_;
    return i;
}


