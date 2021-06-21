// 2021/6/21
// zhangzhong
// 5.6 Pointer Arrays; Pointers to Pointers
// Exercise 5-14. Modify the sort program to handle a -r flag, which indicates sorting 
//                in reverse(decreasing) order.
// Exercise 5-15. Add the options -f to fold upper and lower case together, so that 
//                case distinctions are not made during sorting.
// Exercise 5-16. Add the -d("directory order") option, which makes comparisons only 
//                on letters, numbers and blanks. ??? I do not understand ???
// Exercise 5-17. Add a field-searching capability, so sorting may be done on fields
//                within lines, each field sorted according to an independent set of 
//                options. ??? also do not understand ???
//
// read all the lines of input
// sort them
// print them in order

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_LINES (4096)

static int sort_strcmp(const void* lhs, const void* rhs)
{
    return strcmp(*(const char**)lhs, *(const char**)rhs);
}

static int reverse_sort_strcmp(const void* lhs, const void* rhs)
{
    return sort_strcmp(rhs, lhs);
}

static int sort_numcmp(const void* lhs, const void* rhs)
{
    return (ssize_t)strlen(*(const char**)lhs) - (ssize_t)strlen(*(const char**)rhs);
}

static int reverse_sort_numcmp(const void* lhs, const void* rhs)
{
    return sort_numcmp(rhs, lhs);
}

static int sort_foldcmp(const void* lhs, const void* rhs)
{
    return strcasecmp(*(const char**)lhs, *(const char**)rhs);
}

static int reverse_sort_foldcmp(const void* lhs, const void* rhs)
{
    return sort_foldcmp(rhs, lhs);
}

#define STRCMP_HANDLER (0)
#define NUMCMP_HANDLER (2)
#define FOLDCMP_HANDLER (4)
static int(*sort_handler[6])(const void*, const void*) = {
    sort_strcmp,
    reverse_sort_strcmp,
    sort_numcmp,
    reverse_sort_numcmp,
    sort_foldcmp,
    reverse_sort_foldcmp,
};

int main(int argc, char* argv[])
{
    bool numcmp_flag = false;
    bool fold_flag = false;
    bool reverse_flag = false;
    while (--argc && (*++argv)[0] == '-')
    {
        char c = '\0';
        while (c = *++argv[0])
        {
            if (c == 'n')
                numcmp_flag = true;
            else if (c == 'r')
                reverse_flag = true;
            else if (c == 'f')
                fold_flag = true;
            else
                exit(EXIT_FAILURE);
        }
    }
    if (numcmp_flag && fold_flag)
        exit(EXIT_FAILURE);

    // read all the lines of input
    char* lines[MAX_LINES] = {};
    char* line = NULL;
    size_t len = 0;
    size_t i = 0;
    for (; i < MAX_LINES; ++i)
    {
        lines[i] = NULL;
        len = 0;
        if (getline(&lines[i], &len, stdin) == -1)
            break;
    }

    // sort them
    int handler = -1;
    if (numcmp_flag)
        handler = NUMCMP_HANDLER;
    else if (fold_flag)
        handler = FOLDCMP_HANDLER;
    else 
        handler = STRCMP_HANDLER;
    if (reverse_flag)
        handler += 1;
    qsort(lines, i, sizeof(char*), sort_handler[handler]);

    // print them in order
    for (size_t j = 0; j < i; ++j)
    {
        printf("%s", lines[j]);
        free(lines[j]);
    }

    exit(EXIT_SUCCESS);
}
