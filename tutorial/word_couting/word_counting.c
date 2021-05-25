// 2021/5/25
// zhangzhong
// word counting
  
#include <stdio.h>

#define IN_WORD     (1) 
#define OUT_WORD    (0) 

int main()
{
    long line_count = 0;
    long word_count = 0; 
    long character_count = 0;
    
    int c = EOF;
    int state = OUT_WORD;
    while ((c = getchar()) != EOF)
    {
        ++character_count;
        if (c == '\n')
        {
            ++line_count;
            state = OUT_WORD; 
        }
        else if (c == ' ' || c == '\t')
        {
            state = OUT_WORD; 
        }
        else if (state == OUT_WORD)
        {
            ++word_count;
            state = IN_WORD;
        }
    }

    printf("%ld %ld %ld\n", line_count, word_count, character_count);
    return 0;
}
