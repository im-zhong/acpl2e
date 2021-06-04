// 2021/6/4
// zhangzhong
// 2.9 Bitwise Operators
// Exercise 2-6. Write a functions setbits(x, p, n, y) that returns x with the n bits
//               that begin at position p set to the rightmost n bits of y, leaving 
//               the other bits unchanged.

#include <stdio.h>
#include <stdlib.h>

unsigned setbits(unsigned x, unsigned p, unsigned n, unsigned y)
{
    unsigned mask = ~(~0 << n);
    return (x & ~(mask << p - n + 1)) | ((y & mask) << p - n + 1);
}

int main(int argc, char* argv[])
{
    if (argc < 5)
    {
        printf("Usage: %s <x:unsigned> <p:unsigned> <n:unsigned> <y:unsigned>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    unsigned x = atoi(argv[1]);
    unsigned p = atoi(argv[2]);
    unsigned n = atoi(argv[3]);
    unsigned y = atoi(argv[4]);
    unsigned r = setbits(x, p, n, y);

    printf("%u\n", r);
    exit(EXIT_SUCCESS);
}
