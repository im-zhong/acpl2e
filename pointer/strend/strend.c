// 2021/6/20
// zhangzhong
// 5.5 Character Pointers and Functions
// Exercise 5-4. Write the function strend(s, t), which returns 1 if the string t cocurs 
//               at the end of the string s, and zero otherwise.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// strend
int strend(const char* s, const char* t)
{
    size_t s_len = strlen(s);
    size_t t_len = strlen(t);
    if (s_len < t_len)
        return 0;

    return strcmp(s + (s_len - t_len), t) == 0 ? 1 : 0;
}

int main(int argc, char* argv[])
{
    if (argc < 3)
    {
        printf("Usage: %s <lhs< <rhs>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    printf("%d\n", strend(argv[1], argv[2]));
    exit(EXIT_SUCCESS);
}
