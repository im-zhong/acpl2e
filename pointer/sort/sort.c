// 2021/6/21
// zhangzhong
// 5.6 Pointer Arrays; Pointers to Pointers
//
// read all the lines of input
// sort them
// print them in order

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINES (4096)

static int sort_strcmp(const void* lhs, const void* rhs)
{
    return strcmp(*(const char**)lhs, *(const char**)rhs);
}

int main(int argc, char* argv[])
{
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
    qsort(lines, i, sizeof(char*), sort_strcmp);

    // print them in order
    for (size_t j = 0; j < i; ++j)
    {
        printf("%s", lines[j]);
        free(lines[j]);
    }

    exit(EXIT_SUCCESS);
}
