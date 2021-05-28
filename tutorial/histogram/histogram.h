// 2021/5/26
// zhangzhong
// 1.6 Arrays
// Exercise 1-13. Write a program to print a histogram of the lengths of words in its input.
//                It is easy to draw the histogram with the bars horizontal;
//                a vertical orientation is more challenging.
// Exercise 1-14. Write a program to print a histogram of the frequencies of different characters
//                in its input.

// The first question is, how to express or describe a histogram:
// 
// The second question is, how to draw the histogram:
//  In Computer Graphics Real-Time Rendering, usually use buffer,
//  it means, we could use a buffer to describe a plane, then we caculate
//  every Point(x, y) on it, then we render it to the screen

#ifndef __HISTOGRAM_H__
#define __HISTOGRAM_H__

#include "c_string.h"

#define HORIZONTAL_CHARACTER    ('-')
#define VERTICAL_CHARACTER      ('|')
#define CROSS_CHARACTER         ('+')
#define ABSCISSA_ARROW          ('>')
#define ORDINATE_ARROW          ('^')
#define BAR_INTERVAL            (0)
#define BAR_LEFT_INTERVAL       (2)
#define BAR_RIGHT_INTERVAL      (BAR_LEFT_INTERVAL)


typedef struct __bar
{
    string name;
    int frequency;
} bar_t;

typedef struct __histogram
{
    bar_t* bars;
    string* frequency_strings;
    size_t size;
} histogram_t;

// 可以在这一步把所有的参数都计算出来
// 然后画的时候就只关心如何绘制就可以了
typedef struct __histogram_options
{
    // user-define
    int horizontal_character;
    int vertical_character;
    int cross_character;
    int abscissa_arrow;
    int ordinate_arrow;
    
    size_t bar_interval;
    size_t bar_left_interval;
    size_t bar_right_interval;

    // auto
    int is_fold;

    int min_frequency;
    int max_frequency;
    
    size_t bar_width;
    size_t frequency_width;

} histogram_options_t;

void init_histogram(bar_t* bars, size_t size,
    histogram_t* histogram, histogram_options_t* histogram_options);

void init_options(histogram_options_t* options);

void draw_histogram(bar_t* bars, size_t size, histogram_options_t* histogram_options);

void destroy_histogram(histogram_t* histogram);

#endif // __HISTOGRAM_H__

