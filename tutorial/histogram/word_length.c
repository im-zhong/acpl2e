
#include "histogram.h"
#include <stdio.h>
#include <stdlib.h>

#define MAX_WORD_LENGTH     (1024)
#define IN_WORD     (1)
#define OUT_WORD    (0)

int main()
{
    // actually we can not know the max word length
    // unless we traverse the text
    // so we need a associative array
    // but c has not
    // so we code it in a very simple situlation
    // we simply declare a large array

    long word_length_frequencies[MAX_WORD_LENGTH + 1];
    for (size_t i = 0; i < MAX_WORD_LENGTH + 1; ++i)
        word_length_frequencies[i] = 0;

    size_t max_word_length = MAX_WORD_LENGTH;

    int c = 0;
    int state = OUT_WORD;
    size_t word_length = 0;
    while ((c = getchar()) != EOF)
    {
        if (c == ' ' || c == '\t' || c == '\n')
        {
            if (state == IN_WORD)
            {
                if (word_length > MAX_WORD_LENGTH)
                    exit(EXIT_FAILURE);

                word_length_frequencies[word_length] += 1;
                if (word_length > max_word_length)
                    max_word_length = word_length;
                word_length = 0;
                state = OUT_WORD;
            }
        }
        else
        {
            ++word_length;
            if (state == OUT_WORD)
                state = IN_WORD;
        }
    }

    size_t size = 0;
    // print
    for (size_t i = 0; i <= max_word_length; ++i)
    {
        if (word_length_frequencies[i] != 0)
        {
            // printf("%3zd |", i);
            // for (long j = 0; j < word_length_frequencies[i]; ++j)
            // {
            //     printf("*");
            // }
            // printf(" %ld\n", word_length_frequencies[i]);
            ++size;
        }
    }

    // assume we want to draw the histogram
    // we need change name and frequency to struct string

    // now we want to convert a number to a string
    // we must first figure out the digit count of the number


    bar_t* bars = (bar_t*)malloc(size * sizeof(bar_t));
    for (size_t i = 0; i < size; ++i)
    {
        bars[i].frequency = 0;
        init_string(&(bars[i].name));
    }

    for (size_t i = 0, j = 0; i < size && j <= max_word_length; ++j)
    {
        if (word_length_frequencies[j] != 0)
        {
            bars[i].frequency = word_length_frequencies[j];
            int_to_string((int)j, &(bars[i].name));
            ++i;
        }
    }

    histogram_options_t options;
    init_options(&options);
    draw_histogram(bars, size, &options);

    // print bars
    // for (size_t i = 0; i < size; ++i)
    // {
    //     print_string(bars[i].name);
    //     printf(": %d\n", bars[i].frequency);
    // }

    // free bar
    for (size_t i = 0; i < size; ++i)
    {
        free_string(&(bars[i].name));
    }
    free(bars);

    return 0;
}
