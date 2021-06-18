// 2021/6/17
// zhangzhong
// stack.c

#include "stack.h"

#define STACK_SIZE (4096)
static double stack[STACK_SIZE] = {};
static int sp = 0;

void push(double value)
{
    stack[sp++] = value;
}

double pop()
{
    return stack[--sp];
}

double top()
{
    return stack[sp - 1];
}

void clear_stack()
{
    sp = 0;
}

void swap_stack()
{
    if (sp > 1)
    {
        double tmp = stack[sp - 1];
        stack[sp - 1] = stack[sp - 2];
        stack[sp - 2] = tmp;
    }
}


