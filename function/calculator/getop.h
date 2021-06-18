// 2021/6/17
// zhangzhong
// getop.h

#ifndef _GETOP_H_
#define _GETOP_H_

#define MAXOP (4096)

#define ADD ('+')
#define SUB ('-')
#define MUL ('*')
#define DIV ('/')
#define MOD ('%')

#define SEP ('\n')
#define ASSIGN ('=')

#define NUM (123)
#define VAR (124)
#define ANS (125)

#define TOP (111)
#define SWP (112)
#define CLR (113)

#define SIN (234)
#define COS (235)
#define TAN (236)
#define EXP (237)
#define POW (238)

// get op from stdin
int getop(char* op);

#endif // _GETOP_H_
