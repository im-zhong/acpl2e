// 2021/6/20
// zhangzhong
// 5.5 Character Pointers and Functions

#include <stdio.h>
#include <stdlib.h>

void my_strcpy(char* dest, const char* src)
{
    while (*dest++ = *src++);
}

int main(int argc, char* argv[])
{
    char message[32] = {};
    my_strcpy(message, "hello, world!");
    printf("%s\n", message);
    exit(EXIT_SUCCESS);
}
