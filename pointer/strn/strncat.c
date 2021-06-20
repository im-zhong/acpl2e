// 2021/6/20
// zhangzhong
// 5.5 Character Pointers and Functions
// strncat

#include <stddef.h>

char* my_strncat(char* dest, const char* src, size_t n)
{
    char* dest_end = dest;
    while (*dest_end++);
    --dest_end;
    
    size_t i = 0;
    for (; i < n && (*dest_end++ = *src++); ++i);
    for (; i < n; ++i)
        *dest_end++ = '\0';
    return dest;
}
