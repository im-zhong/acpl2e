// 2021/6/3
// zhangzhong
// 2.7 Type Conversions
// Exercise 2-3: Write a function htoi(s), which converts a string of hexadecimal digits
//               (including an optional 0x or 0X) into its equivalent integer value.
//               The allowable digits are 0 through 9, a through f, and A through F.

#include <stdio.h>
#include <ctype.h>
#include <string.h>

int my_pow(int base, int p)
{
    int value = 1;
    while (p--)
        value *= base;
    return value;
}

int my_isxdigit(int c)
{
    return (c >= '0' && c <= '9') || (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F');
}

int xtoi(int c)
{
    if (c >= '0' && c <= '9')
        return c - '0';
    else if (c >= 'a' && c <= 'f')
        return c - 'a' + 10;
    else if (c >= 'A' && c <= 'F')
        return c - 'A' + 10;
}

int htoi(const char* str)
{
    int value = 0;
    int n = strlen(str);
    if (n == 0)
        return -1;

    if (n >= 2 && str[0] == '0' && (str[1] == 'x' || str[1] == 'X'))
    {
            str += 2;
            n -= 2;
    }

    char c = '\0';
    while (c = *str++)
    {
        if (my_isxdigit(c))
        {
            value += xtoi(c) * my_pow(16, n - 1);
            --n;
        }
        else
            return -1;
    }
    
    return value;
}

unsigned int htoui_simple(const char* str)
{
    unsigned u = 0U;
    sscanf(str, "%x", &u);
    return u;
}

int main(int argc, char* argv[])
{
    unsigned u = htoui_simple(argv[1]);
    printf("%u\n", u);

    int i = htoi(argv[1]);
    printf("%d\n", i);
    return 0;
}

