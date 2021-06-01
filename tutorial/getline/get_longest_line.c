// 2021/5/29
// zhangzhong
// 1.9 Character Arrays
// Write a program that reads a set of text lines and prints the longest
// Exercise 1-16. Revise the main routine of the longest-line program
//                so it will correctly print the length of arbitrary long
//                input lines, and as much as possible of the text

#include <stdio.h>

#define MAX_LINE_LENGTH (32)

int my_getline(char line[], int length);
int copyline(char dest[], char src[]);

int main(int argc, char* argv[])
{
    char line[MAX_LINE_LENGTH] = {'\0'};
    char max_line[MAX_LINE_LENGTH] = {'\0'};
    int length = 0;
    int max_length = 0;
    while ((length = my_getline(line, MAX_LINE_LENGTH)) != 0)
    {
        if (length > max_length)
        {
            copyline(max_line, line);
            max_length = length;
        }
    }

    printf("length: %d\n%s", max_length, max_line);
    return 0;
}

int my_getline(char line[], int length)
{
    int i = 0;
    int c = EOF;
    
    // Exercise 1-16
    for (; (c = getchar()) != EOF && c != '\n'; ++i)
        if (i < length - 1) line[i] = c;
    // for (; i < length - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    //     line[i] = c;
    
    int real_length = i;
    if (c == '\n')
    {
        ++real_length;
        if (i <= length - 2)
            line[i++] = '\n';
    }

    if (i > length - 1)
        i = length - 1;
    line[i] = '\0';

    return real_length;
}

int copyline(char dest[], char src[])
{
    while (*dest++ = *src++);
}

