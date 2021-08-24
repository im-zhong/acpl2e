// 2021/7/30
// zhangzhong
// hash_table.c

#include "hash.h"
#include "hash_table.h"
#include "list.h"
#include <stdlib.h>

table_t* make_table()
{
    table_t* table = (table_t*)malloc(sizeof(table_t));
    for (int i = 0; i < HASH_TABLE_SIZE; ++i)
        table->table[i] = NULL;
    return table;
}

static list_t* index_list(table_t* table, const char* symbol)
{
    if (table && symbol)
        return table->table[hash(symbol) % HASH_TABLE_SIZE];
    return NULL;
}

void free_table(table_t* table)
{
    if (table != NULL)    
    {
        for (int i = 0; i < HASH_TABLE_SIZE; ++i)
            free_list(table->table[i]);
        free(table);
    }
}

const char* lookup(table_t* table, const char* symbol)
{
    return find_list(index_list(table, symbol), symbol);
}

void install(table_t* table, const char* symbol, const char* replacement)
{
    if (!table || !symbol || !replacement)
        return;

    unsigned index = hash(symbol) % HASH_TABLE_SIZE;
    if (table->table[index] == NULL)
        table->table[index] = make_list();
    insert_list(table->table[index], symbol, replacement);
}

void undef(table_t* table, const char* symbol)
{
    erase_list(index_list(table, symbol), symbol);
}

