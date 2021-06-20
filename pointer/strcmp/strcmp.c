// 2021/6/20
// zhangzhong
// 5.5 Character Pointers and Functions
// strcmp

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int my_strcmp(const char* lhs, const char* rhs)
{
    // find first position that no equal
    while (*lhs && (*lhs == *rhs))
    {
        ++lhs;
        ++rhs;
    }
    return *lhs - *rhs;
}

int main(int argc, char* argv[])
{
    if (argc < 3) 
    {
        printf("Usage: %s <lhs> <rhs>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int result = my_strcmp(argv[1], argv[2]);
    if (result < 0)
        printf("%s < %s\n", argv[1], argv[2]);
    else if (result == 0)
        printf("%s == %s\n", argv[1], argv[2]);
    else
        printf("%s > %s\n", argv[1], argv[2]);

    exit(EXIT_SUCCESS);
}

