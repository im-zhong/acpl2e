// 2021/6/9
// zhangzhong
// 3.5 Loops - While and For
// Exercise 3-3. Write a function expand(s1, s2) that expands shorthand notations like a-z in the s1 into the equivalent
//               complete list like abc...xyz in s2. Allow for letters of either case and digits, and be prepared to 
//               handle cases like a-b-c and a-z0-9 and -a-z. Arrange that a leading or trailing - is taken literally.

// A pair of expressions separated by a comma is evaluated left to right,
// and the type and value of the result are the type and value of the right operand.
// The commas that separate function arguments, variables in declarations, etc., 
// are not comma operations, and do not guarantee left to right evaluation.

#include <stdio.h>
#include <stdlib.h>

void expand(char* s1, const char* s2)
{
    char left = '\0';
    char right = '\0';

    while (*s2)
    {
        if (*s2 == '-')
        {
            if (left != '\0' && (right = *(s2 + 1)) != '\0')
            {
                while (left < right - 1)
                {
                    *s1++ = ++left;
                }
                left = right;
                right = '\0';
                --s1;
            }
            else
            {
                *s1 = *s2;
            }
        }
        else
        {
            *s1 = *s2;
            left = *s2;
        }
        ++s1;
        ++s2;
    }
    *s1 = '\0';
}

int main(int argc, char* argv[])
{
    char s1[4096] = {'\0'};
    const char* s2 = "-a-b-c0-9hello-";

    expand(s1, s2);
    printf("%s\n", s2);
    printf("%s\n", s1);

    exit(EXIT_SUCCESS);
}
