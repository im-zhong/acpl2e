// 2021/6/20
// zhangzhong
// 5.5 Character Pointers and Functions
// strncmp

#include <stddef.h>

int my_strncmp(const char* lhs, const char* rhs, size_t n)
{
    size_t i = 0;
    for (; i < n && *lhs == *rhs; ++i, ++lhs, ++rhs);
    return i == n ? 0 : *lhs - *rhs;
}

