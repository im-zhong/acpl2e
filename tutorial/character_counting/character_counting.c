// 2021/5/25
// zhangzhong
// character counting

#include <stdio.h>

int main()
{
    long count = 0;
    while (getchar() != EOF)
    {
        ++count;
    }
    printf("%ld\n", count);
    return 0;
}
