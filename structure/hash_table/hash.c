// 2021/7/30
// zhangzhong
// hash.c

unsigned hash(const char* str)
{
    unsigned hash_value = 0;
    for (; *str; ++str)
        hash_value = *str + 31 * hash_value;
    return hash_value;
}
