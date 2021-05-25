// 2021/5/25
// zhangzhong
// reverse temperature conversion
// Celsius = (5 / 9) * (Fahrenheit - 32)

#include <stdio.h>

#define LOWER   0.0
#define UPPER   300.0
#define STEP    20.0

int main()
{
    printf("%12s%12s\n", "Fahrenheit", "Celsius");
    for (float fahrenheit = UPPER; fahrenheit >= LOWER; fahrenheit -= STEP)
    {
        printf("%12.2f%12.2f\n", fahrenheit, (fahrenheit - 32) * 5 / 9);
    }
}
