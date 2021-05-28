#include "histogram.h"

int main(int argc, char* argv[])
{
    graphics_t graphics;
    init_graphics(4, 8, 'a', &graphics);
    draw_character(&graphics, 0, 0, '0');
    draw_character(&graphics, 1, 1, '1');
    draw_character(&graphics, 2, 2, '2');
    draw_character(&graphics, 3, 3, '3');

    draw_vertical_line(&graphics, 3, 1, 3, '|');
    draw_horizontal_line(&graphics, 3, 0, 7, '-');

    draw_horizontal_string(&graphics, 2, 0, "hello, world", 10);
    draw_vertical_string(&graphics, 0, 6, "hello, world", 10);

    draw_rectangle(&graphics, 0, 3, 0, 7, '|', '-', '+');
    render(&graphics);
    
}
