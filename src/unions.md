---
title: "Unions"
author: mael.conan
logo: https://avatars.githubusercontent.com/u/96961500?s=200&v=4
---

# Download

[skeleton](practical/unions.tar.gz)

# Goal

The goal of these exercises is to make you familiar with concept of unions, and how to handle it properly.

Here is a variant which contains an union and an enum that represents the current field of the union.

```c
enum type
{
    TYPE_INT,
    TYPE_FLOAT,
    TYPE_CHAR,
    TYPE_STRING
};

union type_any
{
    int int_v;
    float float_v;
    char char_v;
    const char *str_v;
};

struct variant
{
    enum type type;
    union type_any value;
};
```

You'll have to write some functions using this variant.

# Variant display

Write a function that will print the content of the variant, followed by a line break.

```c
void variant_display(const struct variant *v);
```

# Equal

Write a function if two variants have the same value **and** the same content.

```c
int variant_equal(const struct variant *first, const struct variant *second);
```

# Find

Write a function that will look for an element in a variant array and returns the number of occurences of the element in the array.

```c
size_t variant_find(const struct variant *array, size_t len, enum type type,
                 union type_any value);
```

# Is sorted

Write a function that will check if an array of variants is sorted. You must convert the data types if they are not the same without explicit cast.

```c
int variant_is_sorted(const struct variant *array, size_t len);
```

If the content of a variant is a string, look at
```sh
man atoi
```
in order to convert the string.

# Sum

Write a function that returns the sum of the elements in a variant array. 

```c
int variant_sum(const struct variant *array, size_t len);
```
