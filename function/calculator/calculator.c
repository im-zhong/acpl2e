// 2021/6/17
// zhangzhong
// 4.3 External Variables
// Exercise 4-3. Given the basic framework, it's straightforward to extend the calculator.
//               Add the modules(%) operator and provisions for negative number.
// Exercise 4-4. Add the commands to print the top elements of the stack without poping,
//               to duplicate it, and to swap the top two elements. Add a command to clear
//               the stack.
// Exercise 4-5. Add access to library functions like sin, exp, and pow. See <math.h>
// Exercise 4-6. Add commands for handling variables. It's easy to provide twenty-six
//               Variables with single-letter names. Add a variable for the most recently
//               printed value.
// Exercise 4-7. Write a routine ungets(s) that will push back an entire string onto the 
//               input. Should ungets know about buf and bufp, or should it just use
//               ungetch?
// Exercise 4-8. Suppose that there will never be more than one character of pushback.
//               Modify getch and ungetch accordingly.
// Exercise 4-9. Our getch and ungetch do not handle a pushde-back EOF correctly. Decide
//               what their properties ought to be if an EOF is pushed back, then implement
//               your design.
// Exercise 4-10. An alternate organization uses getline to read an entire input line; this
//                makes getch and ungetch unnecessary. Revise the calculator to use this
//                approach.
// Exercise 4-11. Modify getop so that it dosen't need to use ungetch. Hint: use an internal
//                static variable.

#include "getop.h"
#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// reverse polish notation calculator
int main(int argc, char* argv[])
{
    char op[MAXOP] = {};
    // getop
    // only one line can support
    int type = EOF;
    double lhs = 0.0;
    double rhs = 0.0;
    double answer = 0.0;
    while ((type = getop(op)) != EOF)
    {
        switch (type)
        {
        case NUM:
            push(atof(op));
            break;
        case ANS:
            push(answer);
            break;
        case ADD:
            push(pop() + pop());
            break;
        case SUB:
            rhs = pop();
            lhs = pop();
            push(lhs - rhs);
            break;
        case MUL:
            push(pop() * pop());
            break;
        case DIV:
            rhs = pop();
            lhs = pop();
            push(lhs / rhs);
            break;
        // Exercise 4-3
        case MOD:
            rhs = pop();
            lhs = pop();
            push(fmod(lhs, rhs));
            break;
        // Exercise 4-4
        case TOP:
            printf("%f\n", top());
            break;
        case SWP:
            swap_stack();
            break;
        case CLR:
            clear_stack();
            break;
        // Exercise 4-5
        case SIN:
            push(sin(pop()));
            break;
        case COS:
            push(cos(pop()));
            break;
        case TAN:
            push(tan(pop()));
            break;
        case EXP:
            push(exp(pop()));
            break;
        case POW:
            rhs = pop();
            lhs = pop();
            push(pow(lhs, rhs));
            break;
        case SEP:
            answer = top();
            clear_stack();
            break;
        }
    }

    printf("%f\n", pop());

    // calculate expression manually
    double value = 123.4 + 5.6 * 7 - 8.9 / 10 + exp(1.0) + sin(0.3) + (tan(0.9) - cos(0.6)) + pow(10, -1);
    printf("%f\n", value * 2);

    exit(EXIT_SUCCESS);
}
