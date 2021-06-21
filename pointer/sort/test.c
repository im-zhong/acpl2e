// 2021/6/21
// zhangzhong
// The sample of qsort

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int sort_strcmp(const void* lhs, const void* rhs)
{
    return strcmp(*(const char**)lhs, *(const char**)rhs);
}

int main(int argc, char* argv[])
{
    const char* lines[] = {
        "world",
        "233",
        "hello"
    };
    size_t size = sizeof(lines) / sizeof(const char*);

    qsort(lines, size, sizeof(const char*), sort_strcmp);

    for (size_t i = 0; i < size; ++i)
        printf("%s\n", lines[i]);

    exit(EXIT_SUCCESS);
}
