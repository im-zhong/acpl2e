// 2021/5/28
// zhangzhong
// 1.7 Functions
// power

#include <stdio.h>

int power(int m, int n);

int main(int argc, char* argv[])
{
    for (int i = 0; i < 10; ++i)
        printf("2^%d = %d, -3^%d = %d\n", i, power(2, i), i, power(-3, i));
    return 0;
}

int power(int base, int n)
{
   int p = 1;
   for (int i = 1; i <= n; ++i)
       p *= base;
   return p;
}

