// 2021/6/21
// zhangzhong
// 5.10 Command-line Arguments
// echo

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        printf("Usage: %s <string> ...", argv[0]);
        exit(EXIT_FAILURE);
    }

    for (int i = 1; i < argc; ++i)
        printf("%s%s", argv[i], (i < argc - 1) ? " ": "\n");
    exit(EXIT_SUCCESS);
}
