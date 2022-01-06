#ifndef VOID_ARR_H
#define VOID_ARR_H

#include <stdlib.h>
#include <string.h>

struct void_arr
{
	void *data;
	// Size of each item
	size_t smemb;
	// Number of items
	size_t nmemb;
};

void *get_item(struct void_arr *arr, size_t index);
void set_item(struct void_arr *arr, void *elem, size_t index);
int compare(struct void_arr *arr, size_t item, size_t other);

#endif
