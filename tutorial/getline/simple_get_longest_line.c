// 2021/5/29
// zhangzhong
// 1.9 Character Arrays
// Write a program that reads a set of text lines and prints the longest

#include <stdio.h>

#define MAX_LINE_LENGTH (4096)

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
    
    for (; i < length - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        line[i] = c;
    
    if (c == '\n')
        line[i++] = '\n';
    line[i] = '\0';
    return i;
}

int copyline(char dest[], char src[])
{
    while (*dest++ = *src++);
}

