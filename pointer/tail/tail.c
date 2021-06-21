// 2021/6/21
// zhangzhong
// 5.10 Command_line Arguments
// Exercise 5-13. Write the program tail, which prints the last n lines of its input.
//                By deafult, n is set to 10, let us say, bu it can be changed by an
//                optional argument so that
//                  tail -n
//                prints the last n lines. The program should behave rationally no 
//                matter how unresonable the input or the value of n. Write the program
//                so it makes the best use of available storage; lines should be stored
//                as in the array of pointers.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define DEFAULT_LINENUM (10)

int main(int argc, char* argv[])
{
    int n = DEFAULT_LINENUM; 
    // or get n from arguments
    if (argc > 1)
    {
        if (argc != 3 || strcmp(argv[1], "-n") != 0)
        {
            printf("Usage: %s [-n num]\n", argv[0]);
            exit(EXIT_FAILURE);
        }
        n = atoi(argv[2]);
    }

    char** lines = (char**)calloc(n, sizeof(char*));
    size_t* lens = (size_t*)calloc(n, sizeof(size_t));
    size_t linenum = 0;
    while (getline(&lines[linenum % n], &lens[linenum % n], stdin) != -1)
        ++linenum;

    char* line = NULL;
    for (size_t i = 0; i < n; ++i)
    {
        line = lines[(linenum + i) % n];
        printf("%s", line ? line : "");
        free(line);
    }
    free(lens);
    free(lines);

    exit(EXIT_SUCCESS);
}
