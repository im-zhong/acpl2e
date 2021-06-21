// 2021/6/21
// zhangzhong
// 5.10 Command-line Arguments
// grep: print lines that match pattern form the first argument

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

// options:
//  -v reverse
//  -n line number

static bool xor(bool lhs, bool rhs)
{
    // true,  true : false
    // false, false: false
    // true,  false: true
    // false, true : true
    return lhs != rhs;
}

int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        printf("Usage: %s [-nv] <pattern>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int reverse_flag = 0;
    int linenum_flag = 0;
    while (--argc && (*++argv)[0] == '-')
    {
        char c = '\0';
        while (c = *++argv[0])
        {
            if (c == 'v')
                reverse_flag = 1;
            else if (c == 'n')
                linenum_flag = 1;
            else
                exit(EXIT_FAILURE);
        }
    }
    if (argc != 1)
        exit(EXIT_FAILURE);
    
    char* pattern = *argv;
    char* line = NULL;
    size_t size = 0;
    size_t linenum = 0;
    while (getline(&line, &size, stdin) != -1)
    {
        ++linenum;
        if (xor(strstr(line, pattern), reverse_flag))
        {
            if (linenum_flag)
                printf("%2d: ", linenum);
            printf("%s", line);
        }
    }
    free(line);

    exit(EXIT_SUCCESS);
}
