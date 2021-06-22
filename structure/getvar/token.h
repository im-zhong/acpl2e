// 2021/6/22
// zhangzhong
// token.h

#ifndef _TOKEN_H_
#define _TOKEN_H_

#include <stddef.h>
#include <stdbool.h>

bool is_keyword(const char* src);
int get_token(char** token, size_t* size);

#endif // _TOKEN_H_

