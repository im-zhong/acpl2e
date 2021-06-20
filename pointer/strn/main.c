// 2021/6/20
// zhangzhong
// 5.5 Character Pointers and Functions

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// extern is default for function, so it can be omitted
int my_strncmp(const char*, const char*, size_t);
extern char* my_strncpy(char*, const char*, size_t);
extern char* my_strncat(char*, const char*, size_t);

int main(int argc, char* argv[])
{
    if (argc < 4)
    {
        printf("Usage: %s <lhs> <rhs> <n>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    size_t n = atoi(argv[3]);
    // strncmp
    printf("%d\n", my_strncmp(argv[1], argv[2], n));
    // strncpy
    // strncat
    char string[4096] = {};
    my_strncpy(string, argv[1], n);
    my_strncat(string, argv[2], n);
    printf("%s\n", string);

    // std
    printf("%d\n", strncmp(argv[1], argv[2], n));
    char std_string[4096] = {};
    strncpy(std_string, argv[1], n);
    strncat(std_string, argv[2], n);
    printf("%s\n", std_string);

    exit(EXIT_SUCCESS);
}
