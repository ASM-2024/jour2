---
title: "Macros"
author: mael.conan
logo: https://avatars.githubusercontent.com/u/96961500?s=200&v=4
---

# Download

[skeleton](macros.tar.gz)

# Goal

The goal of these exercises in to make you comfortable with the concept of macros, to be able to use the operators and to produce generic code.


# Declare and set

Write a macro that will declare and set 3 variables:

```c
DECLARE_AND_SET(TYPE, NAME, VALUE)
```

The 3 variables will be:

- A var with the given type, name and value,
- A pointer on the first variable, with ptr\_NAME as its name,
- A string of the given value, with str\_NAME as its name.

Here is an example:

```c
DECLARE_AND_SET(float, asm, 4.2);
/*
** Should create:
** float asm = 4.2;
** float *ptr_asm = &asm;
** char *str_asm = "4.2";
*/
```
