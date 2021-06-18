// 2021/6/17
// zhangzhong
// getop.c

#include "getop.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>

// internal function
// static void fun()
// {
// }

// external function
int getop(char* op)
{
    int c = EOF;
    // skip space
    while ((c = getchar()) != EOF && c != SEP && isspace(c));
    if (c == EOF)
        return EOF;
    if (c == SEP)
        return SEP;
    // if we read SEP, we should 

    // get the whole op into op array
    int i = 0;
    op[i++] = c;
    while ((c = getchar()) != EOF && c != SEP && !isspace(c))
        op[i++] = c;
    op[i] = '\0';
    // only "123\n", like this format will get into this code
    // at this situation, we must push back '\n' to stdin stream
    // so that in the next getop, we could get the 'SEP' to main
    if (c == SEP)
        ungetc(c, stdin);

    // analyze the op's type
    if (i == 1 && (*op == '+' ||
        *op == '-' || *op == '*' || 
        *op == '/' || *op == '%'))
        return *op;
    else if (strcmp(op, "sin") == 0)
        return SIN;
    else if (strcmp(op, "cos") == 0)
        return COS;
    else if (strcmp(op, "tan") == 0)
        return TAN;
    else if (strcmp(op, "exp") == 0)
        return EXP;
    else if (strcmp(op, "pow") == 0)
        return POW;
    else if (strcmp(op, "top") == 0)
        return TOP;
    else if (strcmp(op, "swp") == 0)
        return SWP;
    else if (strcmp(op, "clr") == 0)
        return CLR;
    else if (strcmp(op, "ans") == 0)
        return ANS;
    else 
        return NUM;
}

