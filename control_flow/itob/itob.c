// 2021/6/16
// zhangzhong
// 3.6 Loops - Do-While
// Exercise 3-5. Write the function itob(n, s, b) that converts the inteager n into base b
//               character representation in the string s. In particular, itob(n,s,16)
//               formats s as a hexadecimal integer in s.

#include <stdio.h>
#include <stdlib.h>

char convert(int m)
{
    if (m >= 0 && m <= 9)
        return '0' + m;
    if (m > 9)
        return 'A' + (m - 10);
    return '\0';
}

void itob(int n, char s[], int b)
{
    int i = 0;
    int m = 0;    
    do {
        m = n % b;
        s[i++] = convert(m);
    } while ((n /= b) > 0);
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
        printf("Usage: %s <integer> <base>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char s[4096] = {'\0'};
    int n = atoi(argv[1]);
    int b = atoi(argv[2]);
    itob(n, s, b);
    printf("%s\n", s);
    exit(EXIT_SUCCESS);
}
