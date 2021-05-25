// 2021/5/25
// zhangzhong
// Celsius = (5 / 9) * (Fahrenheit - 32)
// Kelvins = Celsius - 273.15

#include <stdio.h>

int main()
{
    float celsius = 0;
    float fahrenheit = 0;
    float kelvins = 0;

    float lower = 0;
    float upper = 300;
    float step = 20;

    printf("%12s%12s%12s\n", "Fahrenheit", "Celsius", "Kelvins");
    fahrenheit = lower;
    while (fahrenheit <= upper)
    {
        celsius = (fahrenheit - 32) * 5 / 9;
        kelvins = celsius - 273.15;
        printf("%12.2f%12.2f%12.2f\n", fahrenheit, celsius, kelvins);
        fahrenheit += step;
    }

    return 0;
}
