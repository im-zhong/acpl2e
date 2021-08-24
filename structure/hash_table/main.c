// 2021/8/24
// zhangzhong
// 6.6 Table Lookup
// Exercise 6-5. Write a function undef that will remove a name and definition from the
//               table maintained by lookup and install.

#include <hash_table.h>
#include <stdio.h>

int main(int argc, char* argv[])
{
    table_t* table = make_table();

    const char* key = "hello";
    const char* value = "world";

    // install
    install(table, key, value);

    // lookup
    const char* lookup_value = lookup(table, key);
    printf("key: %s, value: %s\n", key, lookup_value);

    // undef
    undef(table, key);
    // lookup
    lookup_value = lookup(table, key);
    if (lookup_value == NULL)
    {
        printf("key: %s undef success.\n", key);
    }

    free_table(table);
}
