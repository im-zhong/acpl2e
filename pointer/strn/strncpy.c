// 2021/6/20
// zhangzhong
// 5.5 Character Pointers and Functions
// strncpy

#include <stddef.h>

char* my_strncpy(char* dest, const char* src, size_t n)
{
    char* pdest = dest;
    while (*src && pdest - dest < n)
        *pdest++ = *src++; 
    while (pdest - dest < n)
        *pdest++ = '\0';
    return dest;
}
