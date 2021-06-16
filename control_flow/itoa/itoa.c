// 2021/6/15
// zhangzhong
// Exercise 3-4. In a two's complement number representation, our version of itoa dose not 
//               handle the largest negative number. Explain why not. Modify it to print
//               that value correctly.

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

// itoa: convert n to characters in s
void itoa(int n, char s[])
{
    // negative mod is machine-relative
    // so we should convert it to positive
    // but the min negative dose not have its
    // absolute value
    // in the simplet way, use a larger integer
    int sign = 1;
    long long ll = n;
    if (ll < 0)
    {
        sign = -1;
        ll = -ll;
    }

    int i = 0;
    do {
        s[i++] = ll % 10 + '0';
    } while ((ll /= 10) > 0);
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';

    char c = '\0';
    --i;
    for (int j = 0; j < i; --i, ++j)
        c = s[i], s[i] = s[j], s[j] = c;
}

int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        printf("Usage: %s <integer>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int n = atoi(argv[1]);
    char s[4096] = {'\0'};
    itoa(n, s);
    printf("%s\n", s);
    exit(EXIT_SUCCESS);
}
