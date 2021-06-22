// 2021/6/22
// zhangzhong
// token.c

#include "token.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

static const char* keywords[] = {
    "auto",
    "break",
    "case",
    "char",
    "const",
    "continue",
    "default",
    "do",
    "double",
    "else",
    "enum",
    "extern",
    "float",
    "for",
    "goto",
    "if",
    "int",
    "log",
    "register",
    "return",
    "short",
    "signed",
    "sizeof",
    "static",
    "struct",
    "switch",
    "typedef",
    "union",
    "unsigned",
    "void",
    "volatile",
    "while",
};

static ssize_t binary_search(const char* ordered_keywords[], ssize_t size, const char* word)
{
    ssize_t low = 0;
    ssize_t high = size;
    while (low < high)
    {
        ssize_t middle = low + ((high - low) >> 1);
        int r = strcmp(ordered_keywords[middle], word);
        if (r < 0)
            low = middle + 1;
        else if (r > 0)
            high = middle;
        else
            return middle;
    }
    return -1;
}

bool is_keyword(const char* src)
{
    return binary_search(keywords, sizeof(keywords) / sizeof(const char*), src) != -1;
}

// isalnum == [a-zA-Z0-9] 
// ishead == [a-zA-Z_]
// istoken == [_a-zA-Z0-9]
static bool ishead(int c)
{
    return c == '_' || isalpha(c);
}

static bool istoken(int c)
{
    return ishead(c) || isdigit(c);
}

// get token from stdin
int get_token(char** token, size_t* size)
{
    // find token head
    int c = EOF;
    while ((c = getchar()) != EOF && !ishead(c));
    if (c == EOF)
        return -1;

    // allocate enough memory
    if (*token == NULL && *size == 0)
    {
        *size = 64;
        *token = realloc(*token, *size);
    }

    // find token tail, until !istoken(c)  
    ssize_t len = 0; 
    do {
        if (len >= *size)
            *token = realloc(*token, *size *= 2);
        (*token)[len++] = c;
    } while ((c = getchar()) != EOF && istoken(c));

    // add a '\0' at the tail
    if (len >= *size)
        *token = realloc(*token, *size *= 2);
    (*token)[len] = '\0';

    return len;
}

