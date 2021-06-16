// 2021/6/15
// zhangzhong
// Exercise 3-4. In a two's complement number representation, our version of itoa dose not 
//               handle the largest negative number. Explain why not. Modify it to print
//               that value correctly.
// Exercise 3-6. Write a version of itoa that accepts three arguments instead of two.
//               The third argument is a minimum field width; the converted number must 
//               be padded with blanks on the left if necessary to make it wide enough.

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

// itoa: convert n to characters in s
void itoa(int n, char s[], int width)
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

    // padded with blanks
    while (i < width)
        s[i++] = ' ';

    s[i] = '\0';
    char c = '\0';
    --i;
    for (int j = 0; j < i; --i, ++j)
        c = s[i], s[i] = s[j], s[j] = c;
}

int main(int argc, char* argv[])
{
    if (argc < 3)
    {
        printf("Usage: %s <integer> <width>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int n = atoi(argv[1]);
    int w = atoi(argv[2]);
    char s[4096] = {'\0'};
    itoa(n, s, w);
    printf("%s\n", s);
    exit(EXIT_SUCCESS);
}
