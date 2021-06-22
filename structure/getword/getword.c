// 2021/6/21
// zhangzhong
// 6.3 Arrays of Structures
// Exercise 6-1. Our version of getword does not properly handle underscores, string
//               constants, comments, or preprocessor control lines.
//               Write a better version.
// getword

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    char* word;
    ssize_t count;
} keyword_t;

static keyword_t keywords[] = {
    {"auto", 0},
    {"break", 0},
    {"case", 0},
    {"char", 0},
    {"const", 0},
    {"continue", 0},
    {"default", 0},
    {"do", 0},
    {"double", 0},
    {"else", 0},
    {"enum", 0},
    {"extern", 0},
    {"float", 0},
    {"for", 0},
    {"goto", 0},
    {"if", 0},
    {"int", 0},
    {"log", 0},
    {"register", 0},
    {"return", 0},
    {"short", 0},
    {"signed", 0},
    {"sizeof", 0},
    {"static", 0},
    {"struct", 0},
    {"switch", 0},
    {"typedef", 0},
    {"union", 0},
    {"unsigned", 0},
    {"void", 0},
    {"volatile", 0},
    {"while", 0},
};

ssize_t binary_search(keyword_t* ordered_keywords, ssize_t size, const char* keyword)
{
    ssize_t low = 0;
    ssize_t high = size;
    while (low < high)
    {
        ssize_t middle = low + ((high - low) >> 1);
        int r = strcmp(ordered_keywords[middle].word, keyword);
        if (r < 0)
            low = middle + 1;
        else if (r > 0)
            high = middle;
        else
            return middle;
    }
    return -1;
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
    while((c = getchar()) != EOF && !ishead(c));
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

int main(int argc, char* argv[])
{
    char* token = NULL;
    size_t size = 0;
    size_t keywords_size = sizeof(keywords) / sizeof(keyword_t);
    while (get_token(&token, &size) != -1)
    {
        ssize_t i = binary_search(keywords, keywords_size, token);
        if (i != -1)
            ++keywords[i].count;
    }

    for (size_t i = 0; i < keywords_size; ++i)
        printf("%8s: %2zd\n", keywords[i].word, keywords[i].count);

    exit(EXIT_SUCCESS);
}

