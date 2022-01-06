#ifndef BUBBLE_SORT_H
#define BUBBLE_SORT_H

#include "void_arr.h"

void bubble_sort(struct void_arr *arr,
				 _Bool (*compare)(void *item, void *other));

#endif
