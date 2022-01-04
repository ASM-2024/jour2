---
title: "Void pointers"
author: raphael.duhen
logo: https://avatars.githubusercontent.com/u/96961500?s=200&v=4
---

# Goal

The goal of these exercises is to make you familiar with the concept of void pointers, and how to use them properly.

Here is a simple struct using a pointer to a void array.

```c
struct void_arr
{
    void *data;
    // Size of each item
    size_t smemb;
    // Number of items
    size_t nmemb;
};
```

# Get item

Write a function that will get the `n`th item of the array.

```c
void *get_item(struct void_arr *arr, size_t index);
```

The function should return NULL if the index is out of bounds.

# Set item

Write a function that will set the value of an element of the list to the first `smemb` bytes of the data pointed to by `elem`.

```c
void set_item(struct void_arr *arr, void *elem, size_t index);
```

# Compare items

Write a function that will compare two elements byte per byte.

```c
int compare(struct void_arr *arr, size_t item, size_t other);
```

The function should return a positive value if `item` > `other`, a negative value if `item` < `other` and `0` if the items are exactly equal.

# Functional Bubble Sort

Write a function that will bubble sort the array based on the comparison function passed as argument.

```c
struct void_arr *bubble_sort(struct void_arr *arr, int (*compare) (void *item, void *other));
```

The function should return a pointer to the start of the array.
