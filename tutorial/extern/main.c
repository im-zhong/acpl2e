// 2021/6/1
// zhangzhong
// 1.10 External Variables and Scope

#include <stdio.h>

// This is a declaration
// so do not allocate storage for it
// but other file will expose their variable
// so this file can linked to it
extern int i;

int main(int argc, char* argv[])
{
    printf("%d\n", i);
    return 0;
}

