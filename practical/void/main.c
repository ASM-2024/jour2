#include <stdio.h>

#include "bubble_sort.h"

#define TYPE char
#define NUMB 10
#define SIZE sizeof(TYPE)

static void print_char(struct void_arr *arr)
{
	char *ptr = arr->data;

	for (size_t i = 0; i < arr->nmemb; i++)
		printf("%d ", ptr[i * arr->smemb]);

	putchar('\n');
}

static _Bool compare_char(void *item, void *other)
{
	char *char_item = item;
	char *char_other = other;

	return *char_item != *char_other;
}

int main(void)
{
	struct void_arr *arr = calloc(1, sizeof(struct void_arr));

	arr->data = calloc(NUMB, SIZE);
	arr->smemb = SIZE;
	arr->nmemb = NUMB;

	TYPE *tmp = calloc(1, SIZE);
	for (size_t i = 1; i <= arr->nmemb; i++)
	{
		*tmp = i;
		set_item(arr, tmp, arr->nmemb - i);
	}
	free(tmp);

	print_char(arr);
	bubble_sort(arr, &compare_char);
	print_char(arr);

	free(arr->data);
	free(arr);

	return 0;
}
