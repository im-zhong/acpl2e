// 2021/6/9
// zhangzhong
// 3.3 Else-If
// Exercise 2-1. Our binary search makes two tests inside the loop, when one would suffice(at the price
//               of more tests outside). Write a version with only one test inside the loop and measure
//               the difference in run-time.

#include <stdio.h>
#include <stdlib.h>

// find x in array, which is decreased
int binary_search(int value, int a[], int n)
{
    int low = 0;
    int high = 0;
    int mid = 0;

    low = 0;
    high = n - 1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (value < a[mid])
            high = mid - 1;
        else if (value > a[mid])
            low = mid + 1;
        else
            return mid;
    }
    // no match
    return -1;
}

int main(int argc, char* argv[])
{
    exit(EXIT_SUCCESS);
}

