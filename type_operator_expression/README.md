# Chapter 2 - Types, Operators and Expressions

- **Declaratons** list the variables to be used, and state what type they have and perhaps 
what thier initial values are.
- **Operators** specify what is to be done to them.
- **Expressions** combine variables and constants to produce new values.
- The **type** of an object determines the set of values it can have and what operations can 
be performed on it.

---

    <limits.h> <float.h> contain symbolic constants for all of these size, along
    with other properties of the machine and comiler.
    TODO: check the two file, and check for new C standard if there is new type
          and check APUE that discuss the limit too.

    TODO: Principles of computer composition, check for floating point's bit arrangement
          also true form,原码，反码，补码

Since an argument of a function call is an expression, type conversion also takes place 
when arguments are passed to functions. **In the absence of a function prototype**, char
and short become int, and float becomes double.
https://stackoverflow.com/questions/17460618/type-conversion-during-function-call-in-c

C Standard:
    gcc manpage: -std=
    cppreference: https://en.cppreference.com/w/c/language/history
    C89/C90 -> C99 -> C11/C17 -> C2x


Conversions take place across assignments; the value of the right side is converted to the type 
of left, which is the type of the result.
A character is converted to an integer, either by sign extension or not.
Longer integers are converted to shorter ones or to chars by dropping the excess high-order bits
float to int cause truncation of any fractional part.
When a double is converted to float, whether the value is rounded or truncated is implementation 
dependent.

the question is, when will convert happend? 

TODO: 整理一下各个类型之间的转换，提升和截断。

TODO: bitwise, rightshift use arithemetic shift or logical shift


| Operators | Associativity | Functionality | Example   | Operands  |
| --------- | ------------- | ------------- | -------   | --------  |
| .         | left          | 成员选择       | object.member | binary |
| ->        | left          | 成员选择       | object.member | binary |
| []        | left          | 下标          | expr[expr] | binary |       
| ()        | left          | 函数调用      | name(expr_list) | binary |
---

| ++ | right | 后置递增 | lvalue++ | unary |
| --------- | ------------- | ------------- | -------   | --------  |
| -- | right | 后置递减 | lvalue-- | unary |
| --- | --- | --- | --- |

What is Associativity
a + b + c
(a + b) + c 
or
a + (b + c)

What is Priority
a + b * c
(a + b) * c
or
a + (b * c)

简单总结一下运算符优先级就可以了


- [x] aaa
- [ ] bbb
- [ ] ccc
