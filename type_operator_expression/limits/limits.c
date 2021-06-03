// 2021/6/2
// zhangzhong
// limits.h & float.h

#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(int argc, char* argv[])
{
    // integer type
    // char
    printf("char bit: %d\n", CHAR_BIT);
    printf("char min: %d\n", CHAR_MIN);
    printf("char max: %d\n", CHAR_MAX);
    // signed char
    printf("signed char min: %d\n", SCHAR_MIN);
    printf("signed char max: %d\n", SCHAR_MAX);
    // unsigned char
    printf("unsigned char max: %d\n", UCHAR_MAX);
    printf("---\n");

    // [signed] short [int]
    printf("short bit: %d\n", sizeof(short));
    printf("short min: %d\n", SHRT_MIN);
    printf("short max: %d\n", SHRT_MAX);
    // unsigned short [int]
    printf("unsigned short max: %u\n", USHRT_MAX);
    printf("---\n");

    // [signed] int
    printf("int bit: %d\n", sizeof(int));
    printf("int min: %d\n", INT_MIN);
    printf("int max: %d\n", INT_MAX);
    // unsigned int
    printf("unsigned int max: %u\n", UINT_MAX);
    printf("---\n");
    
    // [signed] long [int]
    printf("long bit: %d\n", sizeof(long));
    printf("long min: %ld\n", LONG_MIN);
    printf("long max: %ld\n", LONG_MAX);
    // unsigned long [int]
    printf("unsigned long max: %lu\n", ULONG_MAX);
    printf("---\n");

    // C99
    // new type: bool, long long
    // [signed] long long [int]
    printf("long long bit: %d\n", sizeof(long long));
    printf("long long min: %lld\n", LLONG_MIN);
    printf("long long max: %lld\n", LLONG_MAX);
    // unsigned long long [int]
    printf("unsigned long long max: %llu\n", ULLONG_MAX);
    printf("---\n");

    // floating-point type
    // float
    printf("float bit: %d\n", sizeof(float));
    printf("float min: %e\n", FLT_MIN);
    printf("float max: %e\n", FLT_MAX);
    printf("---\n");

    // double
    printf("double bit: %d\n", sizeof(double));
    printf("double min: %e\n", DBL_MIN);
    printf("double max: %e\n", DBL_MAX);
    printf("---\n");

    // long double
    printf("long double bit: %d\n", sizeof(long double));
    printf("long double min: %Le\n", LDBL_MIN);
    printf("long double max: %Le\n", LDBL_MAX);

    return 0;
}
