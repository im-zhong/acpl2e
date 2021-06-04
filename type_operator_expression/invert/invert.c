// 2021/5/4
// zhangzhong
// 2.9 Bitwise Operators
// Exercise 2-7. Write a function invert(x, p, n) that returns x with the n bits that
//               begin at position p inverted, leaving the others unchanged.

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void print_binary(unsigned n)
{
    const int bits = sizeof(unsigned) * CHAR_BIT;
    char binary[bits + 1];
    binary[bits] = '\0';
    for (int i = 0; i < bits; ++i)
    {
        binary[bits - 1 - i] = '0' + (n & 1U);
        n >>= 1;
    }
    printf("%s\n", binary);
}

unsigned invert(unsigned x, unsigned p, unsigned n)
{
    unsigned mask = ~(~0 << n) << p - n + 1;
    return (x & ~mask) | ~(x & mask) & mask;
}

int main(int argc, char* argv[])
{
    if (argc < 4)
    {
        printf("Usage: %s <x:unsigned> <p:unsigned> <n:unsigned>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    unsigned x = atoi(argv[1]);
    unsigned p = atoi(argv[2]);
    unsigned n = atoi(argv[3]);

    printf("befor invert: ");
    print_binary(x);
    unsigned r = invert(x, p, n);
    printf("after invert: ");
    print_binary(r);

    exit(EXIT_SUCCESS);
}

