
#include "histogram.h"
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define CHARACTER_SIZE  (26)

int main()
{
    int character_frequencies[CHARACTER_SIZE];
    for (size_t i = 0; i < CHARACTER_SIZE; ++i)
        character_frequencies[i] = 0;

    int c;
    while ((c = getchar()) != EOF)
    {
        if (isalpha(c))
        {
            c = tolower(c);
            ++character_frequencies[c - 'a'];
        }
    }

    
    for (size_t i = 0; i < CHARACTER_SIZE; ++i)
    {
        printf("%c: %d\n", i + 'a', character_frequencies[i]);
    }

    bar_t* bars;
    size_t size = CHARACTER_SIZE;
    bars = (bar_t*)malloc(size * sizeof(bar_t));
    for (size_t i = 0; i < size; ++i)
    {
        bars[i].frequency = character_frequencies[i];
        init_string(&bars[i].name);
        alloc_string(&(bars[i].name), (char)('a' + i), 1);
    }






    histogram_options_t options;
    init_options(&options);
    draw_histogram(bars, size, &options);


    // free bar
    for (size_t i = 0; i < size; ++i)
    {
        free_string(&(bars[i].name));
    }
    free(bars);

    return 0;
}
