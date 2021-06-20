// 2021/6/20
// zhangzhong
// 5.2 Pointers and Function Arguments
// Exercise 5-2. Write getfloat, the floating-point analog of getint.
//               What type does getfloat return as its functionv value?

#include <stdio.h>
#include <stdlib.h>

size_t getfloat(double* value)
{
    if (value == NULL)
        return 0;

    char* line = NULL;
    size_t size = 0;
    double* pvalue = value;

    char* ptr = NULL;
    char* end = NULL;
    while (getline(&line, &size, stdin) > 0)
    {
        end = line;
        do {
            ptr = end;
            *pvalue++ = strtod(ptr, &end);
        } while (ptr != end);
    }
    free(line);

    return pvalue - value - 1;
}

int main(int argc, char* argv[])
{
    double array[4096] = {};
    size_t size = getfloat(array);
    for (size_t i = 0; i < size; ++i)
        printf("%f\n", array[i]);
    exit(EXIT_SUCCESS);
}
