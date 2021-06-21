// 2021/6/21
// zhangzhong
// 5.7 Multi-dimensional Arrays

// which year, which month, which day
// i can tell it is the day in the year

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

static int day_of_month[2][12] = {
    // leap
    {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    // non-leap
    {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

bool is_leap(int year)
{
    return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
}

int to_day(int year, int month, int day)
{
    int leap = is_leap(year) ? 0 : 1; 
    int day_of_year = 0;
    for (int m = 0; m < month - 1; ++m)
        day_of_year += day_of_month[leap][m];
    day_of_year += day;
    return day_of_year;
}

int main(int argc, char* argv[])
{
    if (argc < 4)
    {
        printf("Usage: %s <year> <month> <day>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int year = atoi(argv[1]);
    int month = atoi(argv[2]);
    int day = atoi(argv[3]);

    printf("%d\n", to_day(year, month, day));
    exit(EXIT_SUCCESS);
}
