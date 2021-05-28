#include "graphics.h"
#include <stdio.h>
#include <stdlib.h>

int init_graphics(size_t height, size_t width, int character, graphics_t* graphics)
{
    int* buffer = NULL;
    size_t size = height * width;
    if (buffer = (int*)malloc(size * sizeof(int)))
    {
        for (size_t i = 0; i < size; ++i)
        {
            buffer[i] = character;
        }
    }
    if (graphics == NULL)
    {
        return -1;
    }

    graphics->buffer = buffer;
    graphics->height = height;
    graphics->width = width;

    return 0;
}


void draw_character(graphics_t* graphics, size_t height, size_t width, int character)
{
    if (graphics == NULL)
        return;
    if (height >= graphics->height || width >= graphics->width)
        return;

    // height < graphics->height && width < graphics->width
    graphics->buffer[height * graphics->width + width] = character;
}

void draw_horizontal_string(graphics_t* graphics, size_t height, size_t width, const char* string, size_t length)
{
    if (graphics == NULL)
        return;
    if (height >= graphics->height || width >= graphics->width)
        return;
    if (string == NULL || length == 0)
        return;

    for (size_t i = 0; i < length; ++i)
    {
        if (width + i >= graphics->width)
            return;
        draw_character(graphics, height, width + i, string[i]);
    }
}

void draw_vertical_string(graphics_t* graphics, size_t height, size_t width, const char* string, size_t length)
{
    if (graphics == NULL)
        return;
    if (height >= graphics->height || width >= graphics->width)
        return;
    if (string == NULL || length == 0)
        return;

    for (size_t i = 0; i < length; ++i) 
    {
        if (height + i >= graphics->height)
            return;
        draw_character(graphics, height + i, width, string[i]);
    }
}


void draw_vertical_line(graphics_t* graphics, size_t up, size_t down, size_t width, int character)
{
    if (graphics == NULL)
        return;
    if (up >= graphics->height || down >= graphics->height || width >= graphics->width)
        return;
    
    if (up > down)    
    {
        size_t tmp = up;
        up = down;
        down = tmp;
    }

    for (size_t height = up; height <= down; ++height)
    {
        draw_character(graphics, height, width, character);
    }
}


void draw_horizontal_line(graphics_t* graphics, size_t height, size_t left, size_t right, int character)
{
    if (graphics == NULL)
       return;
    
    if (height >= graphics->height || left >= graphics->width || right >= graphics->width) 
        return;

    if (left > right)
    {
        size_t tmp = left;
        left = right;
        right = tmp;
    }

    for (size_t width = left; width <= right; ++width)
    {
        draw_character(graphics, height, width, character);
    }
}

void draw_rectangle(graphics_t* graphics, size_t up, size_t down, size_t left, size_t right,
    int horizontal_character, int vertical_character, int cross_character)
{
    draw_horizontal_line(graphics, up, left, right, horizontal_character);
    draw_horizontal_line(graphics, down, left, right, horizontal_character);

    draw_vertical_line(graphics, up, down, left, vertical_character);
    draw_vertical_line(graphics, up, down, right, vertical_character);

    draw_character(graphics, up, left, cross_character);
    draw_character(graphics, up, right, cross_character);
    draw_character(graphics, down, left, cross_character);
    draw_character(graphics, down, right, cross_character);
}

void render(graphics_t* graphics)
{
    int* buffer = graphics->buffer;
    if (buffer == NULL)
    {
        return;
    }

    size_t size = graphics->height * graphics->width;
    if (size == 0)
    {
        return;
    }

    putchar(buffer[0]);
    for (size_t i = 1; i < size; ++i)
    {
        if (i % graphics->width == 0)  
        {
            putchar('\n');
        }
        putchar(buffer[i]);
    }
}

void destroy_graphics(graphics_t* graphics)
{
    if (graphics != NULL)
    {
        free(graphics->buffer);
        graphics->height = 0;
        graphics->width = 0;
    }
}
