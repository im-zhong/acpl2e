// 2021/6/4
// zhangzhong
// 2.10 Assignment Operators and Expression
// Exercise 2-9. In a two's complement number system, x &= (x-1) deletes the rightmost 
//               1-bit in x. Explain why. Use this ovservation to write a faster version
//               of bitcount.
//
// A: Why x &= (x-1) deletes the rightmost 1-bit in x.
// ...1 -1 = ...0, then & ...1 = ...0, delete the rightmost 1-bit in ...1
// ..10 -1 = ..01, then & ..10 = ..00, delete the rightmost 1-bit in ..10  
// .100 -1 = .001, then & .100 = .000, delete the rightmost 1-bit in .100
// ...
// as you can see, right bits set to zero, and left bits unchanged.

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// count 1-bit in n
int bitcount(unsigned n)
{
    int bits = 0;
    for (; n != 0; n >>= 1)
        if (n & 1U)
            ++bits;
    return bits;
}

int fast_bitcount(unsigned n)
{
    int bits = 0;
    while (n != 0)
    {
        n &= (n - 1);
        ++bits;
    }
    return bits;
}

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

int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        printf("Usage: %s <n:unsigned>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    unsigned n = atoi(argv[1]);
    print_binary(n);
    printf("%d\n", bitcount(n));
    printf("%d\n", fast_bitcount(n));
    exit(EXIT_SUCCESS);
}
