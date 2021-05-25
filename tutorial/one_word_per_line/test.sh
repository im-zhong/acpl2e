#! /bin/bash
# 2021/5/26
# zhangzhong

for file in "$@"; do
    cat ${file} | ./one_word_per_line.out | wc -l > one_word_per_line.tmp
    cat ${file} | wc -w > wc.tmp
    diff one_word_per_line.tmp wc.tmp
done
