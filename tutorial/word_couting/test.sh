#! /bin/bash
# 2021/5/25
# zhangzhong

for file in "$@"; do
    cat ${file} | wc | awk '{print $1, $2, $3}' > wc.tmp
    cat ${file} | ./word_counting.out | awk '{print $1, $2, $3}' > word_counting.tmp 
    diff wc.tmp word_counting.tmp
done

