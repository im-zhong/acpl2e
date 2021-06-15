// 2021/6/9
// zhangzhong
// 3.4 Switch
// Exercise 3-2. Write a function escape(s,t) that converts characters like newline and tab into
//               visible escape sequences liek \n and \t as it copies the string t to s. Use a 
//               switch. Write a function for the other direction as well, converting escape into
//               the real characters.

#include <stdio.h>
#include <stdlib.h>

void escape(char* s, const char* t)
{
    while (*t)
    {
        switch (*t)
        {
            case '\n': *s = '\\'; ++s; *s = 'n'; break;
            case '\t': *s = '\\'; ++s; *s = 't'; break;
            default: *s = *t; break;
        }
        ++t;
        ++s;
    }
    *s = '\0';
}

void reverse_escape(char* s, const char* t)
{
    while (*t)
    {
        if (*t == '\\')
        {
            if (*(t + 1) == 'n')
            {
                ++t;
                *s = '\n';
            }
            else if (*(t + 1) == 't')
            {
                ++t;
                *s = '\t';
            }
            else
            {
                *s = *t;
            }
        }
        else
        {
            *s = *t;
        }
        ++t;
        ++s;
    }
    *s = '\0';
}

int main(int argc, char* argv[])
{
    char s[4096] = {'\0'};
    const char* t = "\thello, world\n";

    printf("%s", t);
    escape(s, t);
    printf("%s", s);

    char rs[4096] = {'\0'};
    reverse_escape(rs, s);
    printf("%s", rs);

    exit(EXIT_SUCCESS);
}

