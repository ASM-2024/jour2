#include "void_arr.h"

void *get_item(struct void_arr *arr, size_t index)
{
	char *ptr = arr->data;
	size_t offset = index * arr->smemb;

	return offset > arr->smemb * arr->nmemb ? NULL : ptr + index;
}

void set_item(struct void_arr *arr, void *elem, size_t index)
{
	char *ptr = get_item(arr, index);
	if (ptr)
		memcpy(ptr, elem, arr->smemb);
}

int compare(struct void_arr *arr, size_t item, size_t other)
{
	char *item_ptr = get_item(arr, item);
	char *other_ptr = get_item(arr, other);

	for (size_t i = 0; i < arr->smemb && *item_ptr++ == *other_ptr++; i++)
		continue;

	if (!*item_ptr && !*other_ptr)
		return 0;

	return *item_ptr > *other_ptr ? 1 : -1;
}
