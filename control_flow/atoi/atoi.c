// 2021/6/15
// zhangzhong
// atoi: convert s to integer

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int my_atoi(const char* s)
{
    int i, n, sign;

    // skip white space, if any
    for (i = 0; isspace(s[i]); ++i);

    // get sign, if any
    sign = ((s[i] == '-') ? -1 : 1);
    if (s[i] == '-' || s[i] == '+')
        ++i;

    // get integer part and convert it
    // example: 123
    // at first, n = 10 * 0 + 1 = 1
    // then, n = 10 * 1 + 2 = 12
    // then, n = 10 * 12 + 3 = 123
    for (n = 0; isdigit(s[i]); ++i)
        n = 10 * n + (s[i] - '0');

    return sign * n;
}

int main(int argc, char* argv[])
{
    // stdlib.h: atoi 
    if (argc < 2)
    {
        printf("Usage: %s <integer>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    printf("std_atoi: %d\n", atoi(argv[1]));
    printf("my_atoi : %d\n", my_atoi(argv[1]));
    exit(EXIT_SUCCESS);
}
