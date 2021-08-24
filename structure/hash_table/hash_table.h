// 2021/7/30
// zhangzhong
// hash_table.h

#include "list.h"

#define HASH_TABLE_SIZE 1024

// lookup, install, undef
typedef struct hash_table_type
{
    list_t* table[HASH_TABLE_SIZE];
}table_t;

table_t* make_table();

void free_table(table_t* table);

const char* lookup(table_t* table, const char* symbol);

void install(table_t* table, const char* symbol, const char* replacement);

void undef(table_t* table, const char* symbol);

