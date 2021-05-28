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

#include "histogram.h"
#include "graphics.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int find_min_max_frequency(bar_t* bars, size_t size, int* min_frequency, int* max_frequency)
{
    if (bars == NULL || size == 0)
        return -1;

    int min = bars[0].frequency;
    int max = min;
    int frequency = 0;
    for (size_t i = 1; i < size; ++i)
    {
        frequency = bars[i].frequency;
        if (min > frequency) min = frequency;
        if (max < frequency) max = frequency;
    }
    if (max_frequency) *max_frequency = max;
    if (min_frequency) *min_frequency = min;
    return 0;
}

// void find_max_size(histogram_t* histogram, size_t* max_name_size, size_t* max_frequency_size)
// {
//     if (histogram == NULL)
//         return;
    
//     size_t name_size = 0;
//     size_t frequency_size = 0;
//     for (size_t i = 0; i < histogram->size; ++i)
//     {
//         if (name_size > histogram->abscissa[i].size)
//             name_size = histogram->abscissa[i].size;
//         if (frequency_size > histogram->ordinate[i].size)
//             frequency_size = histogram->ordinate[i].size;
//     }
// }

int find_max_string(string* data, size_t size, size_t* max_index)
{
    if (data == NULL || size == 0 || max_index == NULL)
        return -1;

    size_t index = 0;
    for (size_t i = 1; i < size; ++i)
    {
        if (data[index].size < data[i].size)
            index = i;
    }
    *max_index = index;
    return 0;
}

void find_max_bar_width(bar_t* bars, size_t size, size_t* max_bar_width)
{
    if (bars == NULL || size == 0 || max_bar_width == 0)
        return;

    size_t name_size = 0;
    for (size_t i = 0; i < size; ++i)
    {
        if (name_size < bars[i].name.size)
            name_size = bars[i].name.size;
    }
    *max_bar_width = name_size + 2;
}

void init_histogram(bar_t* bars, size_t size,
    histogram_t* histogram, histogram_options_t* options)
{
    if (bars == NULL || size == 0 ||
        histogram == NULL || options == NULL)
        return;

    // min_frequency & max_frequency
    find_min_max_frequency(bars, size, &options->min_frequency, &options->max_frequency);

    if (options->min_frequency > 3)
        options->is_fold = 1;

    // bar_width = max_name_size + 2
    find_max_bar_width(bars, size, &options->bar_width);

    // frequency_width

    // 这里声明一个新的histogram变量
    histogram->bars = bars;
    histogram->size = size;
    histogram->frequency_strings = (string*)malloc(size * sizeof(string));
    for (size_t i = 0; i < size; ++i)
    {
        init_string(&(histogram->frequency_strings[i]));
        int_to_string(bars[i].frequency, &(histogram->frequency_strings[i]));
    }

    size_t index = 0;
    find_max_string(histogram->frequency_strings, histogram->size, &index);
    options->frequency_width = histogram->frequency_strings[index].size;

        

    // // histogram->size = size;
    // // histogram->abscissa = (string*)malloc(size * sizeof(string));
    // // for (size_t i = 0; i < size; ++i)
    // //     init_string(&(histogram->abscissa[i]));
    // // histogram->ordinate = (string*)malloc(size * sizeof(string));
    // // for (size_t i = 0; i < size; ++i)
    // //     init_string(&(histogram->ordinate[i]));

    // for (size_t i = 0; i < size; ++i)
    // {
    //     // 首先分析横坐标 abscissa
        
    //     // 这个应该写成一个函数
    //     // copy_string(&(histogram->abscissa[i]), bars[i].name.data, bars[i].name.size);

    //     // 然后是纵坐标
    //     // ordiante
    //     // int -> string
    //     int_to_string(bars[i].frequency, &(histogram->ordinate[i]));
    // }
}

void init_options(histogram_options_t* options)
{
    options->horizontal_character = HORIZONTAL_CHARACTER;
    options->vertical_character = VERTICAL_CHARACTER;
    options->cross_character = CROSS_CHARACTER;
    options->abscissa_arrow = ABSCISSA_ARROW;
    options->ordinate_arrow = ORDINATE_ARROW;

    options->bar_interval = BAR_INTERVAL;
    options->bar_left_interval = BAR_LEFT_INTERVAL;
    options->bar_right_interval = BAR_RIGHT_INTERVAL;

    options->min_frequency = 0;
    options->max_frequency = 0;
    options->is_fold = 0;
    options->bar_width = 0;
    options->frequency_width = 0;
}

void get_origin(graphics_t* graphics, histogram_options_t* options, point_t* origin)
{
    if (graphics == NULL || options == NULL || origin == NULL)
        return;
    origin->height = graphics->height - 2;
    origin->width = options->frequency_width + 1;
}

void draw_coordinate(graphics_t* graphics, histogram_options_t* options)
{
    point_t origin;
    get_origin(graphics, options, &origin);

    point_t abscissa_arrow;
    abscissa_arrow.height = origin.height;
    abscissa_arrow.width = graphics->width - 1;

    draw_horizontal_line(graphics, origin.height, origin.width, abscissa_arrow.width, options->horizontal_character);
    draw_character(graphics, abscissa_arrow.height, abscissa_arrow.width, options->abscissa_arrow);

    point_t ordinate_arrow;
    ordinate_arrow.height = 0;
    ordinate_arrow.width = origin.width;
    draw_vertical_line(graphics, ordinate_arrow.height, origin.height, origin.width, options->vertical_character);
    draw_character(graphics, ordinate_arrow.height, ordinate_arrow.width, options->ordinate_arrow);

    if (options->is_fold)
    {
        draw_character(graphics, origin.height - 1, origin.width, '<');
        draw_character(graphics, origin.height - 2, origin.width, '>');
    }

    draw_character(graphics, origin.height, origin.width, options->cross_character);
}

size_t right_align(size_t left, size_t right, size_t size)
{
    if (right > left)
    {
        size_t tmp = left;
        left = right;
        right = tmp;
    }

    size_t distance = right - left + 1;
    if (distance <= size)
        return left;

    return right - size + 1;
}

// 这个函数这么看起来实现的并不合理啊
// 讲道理坐标可以是负的啊
// right - left + 1 > size
size_t mid_align(size_t left, size_t right, size_t size)
{
    printf("mid align: left = %zd, right = %zd, size = %zd\n", left, right, size);
    // 1 left < right
    if (left > right)
    {
        size_t tmp = left;
        left = right;
        right = tmp;
    }

    // 2 right - left + 1 > size
    size_t distance = right - left + 1;
    if (distance <= size)
        return left;

    if (distance % 2 == 0 && size % 2 == 0)
        return left + (distance - size) / 2;
    else if (distance % 2 == 1 && size % 2 == 1)
        return mid_align(left, right - 1, size - 1);
    else
    {
        if (size == 0)
            return left + distance / 2;
        else
            return mid_align(left, right, size - 1);
    }
}



void draw_bar(graphics_t* graphics, histogram_t* histogram, histogram_options_t* options)
{
    // bar: up down left right
    point_t origin;
    get_origin(graphics, options, &origin);

    size_t down = origin.height;
    size_t up = 0;
    size_t left = 0;
    size_t right = 0;
    for (size_t i = 0; i < histogram->size; ++i)
    {
        if (options->is_fold)
            up = origin.height - 2 - (histogram->bars[i].frequency - options->min_frequency + 1);
        else
            up = origin.height - histogram->bars[i].frequency;
        left = origin.width + options->bar_left_interval + 
            (options->bar_width + options->bar_interval) * i;
        right = left + options->bar_width - 1;

        draw_rectangle(graphics, up, down, left, right, 
            options->horizontal_character, options->vertical_character, 
            options->cross_character);

        // draw name
        
        size_t width = mid_align(left, right, histogram->bars[i].name.size);
        draw_horizontal_string(graphics, origin.height + 1, width, 
            histogram->bars[i].name.data, histogram->bars[i].name.size);

        printf("bar: %zd, left = %zd, right = %zd, mid = %zd\n", i, left, right, width);

        // draw_horizontal_string(graphics, origin.height + 1, 0, 
        //     "hello, world", 12);
    }   
}

void draw_frequency(graphics_t* graphics, histogram_t* histogram, histogram_options_t* options)
{
    if (graphics == NULL || histogram == NULL || options == NULL)
        return;

    point_t origin;
    get_origin(graphics, options, &origin);

    size_t height = 0;
    size_t left = 0;
    size_t right = left + options->frequency_width - 1;
    for (size_t i = 0; i < histogram->size; ++i)
    {
        if (options->is_fold)
            height = origin.height - 2 - (histogram->bars[i].frequency - options->min_frequency + 1);
        else
            height = origin.height - histogram->bars[i].frequency;

        draw_horizontal_string(graphics, height, right_align(left, right, histogram->frequency_strings[i].size),
            histogram->frequency_strings[i].data, histogram->frequency_strings[i].size);
    }
}

void draw_histogram_impl(histogram_t* histogram, histogram_options_t* options)
{
    // first, caculate the height, length
    if (histogram == NULL) 
        return;

    if (options == NULL)
        return;

    // int min_frequency = 0;
    // int max_frequency = 0;
    // find_min_max_frequency(histogram, &min_frequency, &max_frequency);

   
    // height = 1 + 1 + 1 + 1 + (max - min + 1) + 1
    // weight = ordinate_width + 1 + bar_width * bar_count + bar_interval * (bar_size - 1) + bar_left + bar_right + 1 


    // width =  frequency_width + space:1 + ordinate_axis_width:1 + 
    //          bar_left_interval + bar_width * size + bar_interval * (size - 1)
    //          bar_righrt_interval + abscissa_arrow_width:1
    size_t width =  options->frequency_width + 1 + 1 + options->bar_interval +
                    options->bar_width * histogram->size + 
                    options->bar_interval * (histogram->size - 1) +
                    options->bar_right_interval + 1;

    // height = ordinate_arrow_height:1 + (max_frequency - min_frequency + 1) +
    //          folder:2 + abscissa_axis_height:1 + name_height:1
    size_t height = 1 + options->max_frequency - options->min_frequency + 1 +
                    2 + 1 + 1;

    graphics_t graphics;
    init_graphics(height, width, ' ', &graphics);

    draw_coordinate(&graphics, options);

    draw_bar(&graphics, histogram, options);

    draw_frequency(&graphics, histogram, options);

    // draw coordinate

    // draw every bar

    render(&graphics);

    // 咱在这里输出一下所有的参数
    // histogram
    // char name[64];
    // char frequency[64];
    // for (size_t i = 0; i < histogram->size; ++i)
    // {
    //     // name : frequency
    //     strncpy(name, histogram->abscissa[i].data, histogram->abscissa[i].size);
    //     name[histogram->abscissa[i].size] = '\0';

    //     strncpy(frequency, histogram->ordinate[i].data, histogram->ordinate[i].size);
    //     frequency[histogram->ordinate[i].size] = '\0';
    //     printf("%s: %s", name, frequency);
    // }
    // for (size_t i = 0; i < histogram->size; ++i)
    // {
    //     print_string(histogram->bars[i].name);
    //     printf(": %d, ", histogram->bars[i].frequency);
    //     print_string(histogram->frequency_strings[i]);
    //     printf("\n");
    // }

    // // options

    // printf("horizontal character: %c\n", options->horizontal_character);
    // printf("vertical_character: %c\n", options->vertical_character);
    // printf("cross_character: %c\n", options->cross_character);
    // printf("abscissa_arrow: %c\n", options->abscissa_arrow);
    // printf("ordinate_arrow: %c\n", options->ordinate_arrow);

    // printf("bar_interval: %zd\n", options->bar_interval);
    // printf("bar_left_interval: %zd\n", options->bar_left_interval);
    // printf("bar_right_interval: %zd\n", options->bar_right_interval);

    // printf("min_frequency: %d\n", options->min_frequency);
    // printf("max_frequency: %d\n", options->max_frequency);

    // printf("bar_width: %d\n", options->bar_width);
    // printf("frequency_width: %d\n", options->frequency_width);


    // printf("height: %zd\n", height);
    // printf("width: %zd\n", width);

    // destroy graphics
    destroy_graphics(&graphics);
}

void draw_histogram(bar_t* bars, size_t size, histogram_options_t* options)
{
    histogram_t histogram;
    init_histogram(bars, size, &histogram, options);
    
    draw_histogram_impl(&histogram, options);

    destroy_histogram(&histogram);
}

void destroy_histogram(histogram_t* histogram)
{
    if (histogram == NULL)
        return;

    for (size_t i = 0; i < histogram->size; ++i)
    {
        free_string(&(histogram->frequency_strings[i]));
    }
    free(histogram->frequency_strings);

    histogram->bars = NULL;
    histogram->frequency_strings = NULL;
    histogram->size = 0;
}
