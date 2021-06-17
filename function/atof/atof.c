// 2021/6/16
// zhangzhong
// 4.2 Functions Returning Non-integers
// Exercise 4-2. Extend atof to handle scientific notation of the form 123.45e-6,
//               where a floating-point number may be followed by e or E and an 
//              optionally signed exponent.

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

double my_atof(const char* s)
{
    // skip white space
    int i = 0;
    for (; isspace(s[i]); ++i);

    // get sign
    double sign = 1.0;
    sign = ((s[i] == '-') ? -1.0 : 1.0);
    if (s[i] == '-' || s[i] == '+')
        ++i;

    double value = 0.0;
    for (;isdigit(s[i]); ++i)
        value = value * 10.0 + (s[i] - '0');

    if (s[i] == '.')
    {
        ++i;
        double fractional = 0.0; 
        int k = 0;
        for (;isdigit(s[i]); ++i, ++k) 
            fractional = fractional * 10 + (s[i] - '0');
        value += fractional * pow(10.0, -k);
    }

    if (s[i] == 'e' || s[i] == 'E')
    {
        ++i;
        int exponent = 0;
        // maybe sign
        int exponent_sign = 1;
        exponent_sign = ((s[i] == '-') ? -1 : 1);
        if (s[i] == '-' || s[i] == '+')
            ++i;
        for (; isdigit(s[i]); ++i) 
            exponent = exponent * 10 + (s[i] - '0');
        value *= pow(10, exponent_sign * exponent);
    }

    return sign * value;
}

double lib_atof(const char* s)
{
    char* p = (char*)s;
    long long integer = 0;
    integer = strtoll(s, &p, 10);
    double sign = ((integer < 0) ? -1.0 : 1.0);
    integer = llabs(integer);

    long long fraction = 0;
    int precision = 0;
    if (*p == '.')
    {
        ++p;
        char* q = p;
        fraction = strtoll(p, &q, 10);
        precision = q - p;
        p = q;
    }

    long long exponent = 0;
    if (*p == 'e' || *p == 'E')
    {
        ++p;
        exponent = strtoll(p, &p, 10);
    }

    return sign * ((double)integer + (double)fraction * pow(10, -precision)) * pow(10, exponent);
}


int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        printf("Usage: %s <double>\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    printf("%f\n", atof(argv[1]));
    printf("%f\n", my_atof(argv[1]));
    printf("%f\n", lib_atof(argv[1]));
    exit(EXIT_SUCCESS);
}


