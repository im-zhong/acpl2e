// 2021/5/27
// zhangzhong
// 

#ifndef __GRAPHICS_H__
#define __GRAPHICS_H__

#include <sys/types.h>

// how to define a histogram
// int horizontal_character;
// int vertical_character;
// int cross_character;
// 
// int* ordinate_axis;
// int* abscissa_axis;

typedef struct __graphics
{
    int* buffer;
    size_t height;
    size_t width;
} graphics_t;

typedef struct __point
{
    size_t height;
    size_t width;
} point_t;

int init_graphics(size_t height, size_t width, int character, graphics_t* graphics);

void draw_character(graphics_t* graphics, size_t height, size_t width, int character);

void draw_horizontal_string(graphics_t* graphics, size_t height, size_t width, const char* string, size_t length);

void draw_vertical_string(graphics_t* graphics, size_t height, size_t width, const char* string, size_t length);

void draw_vertical_line(graphics_t* graphics, size_t up, size_t down, size_t width, int character);

void draw_horizontal_line(graphics_t* graphics, size_t height, size_t left, size_t right, int character);

void draw_rectangle(graphics_t* graphics, size_t up, size_t down, size_t left, size_t right,
   int horizontal_character, int vertical_character, int cross_character);

void render(graphics_t* graphics);

void destroy_graphics(graphics_t* graphics);


#endif // __GRAPHICS_H__
