// 2021/6/4
// zhangzhong
// 2.9 Bitwise Operators
// Exercise 2-8. Write a function rightrot(x, n) that returns the value of integer x
//               rotated to the right by n positions.

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

unsigned rotate_shift_right(unsigned n)
{
    unsigned last_bit = n & 1U;
    return (n >> 1) | (last_bit << (sizeof(unsigned) * CHAR_BIT - 1));
}

unsigned rightrot(unsigned x, unsigned n)
{
    while (n--)
        x = rotate_shift_right(x);
    return x;
}

int main(int argc, char* argv[])
{
    if (argc < 3)
    {
        printf("Usage: %s <x:unsigned> <n:unsigned>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    unsigned x = atoi(argv[1]);
    unsigned n = atoi(argv[2]);
    unsigned r = rightrot(x, n);

    printf("befor rotate: ");
    print_binary(x);
    printf("after rotate: ");
    print_binary(r);

    exit(EXIT_SUCCESS);
}
