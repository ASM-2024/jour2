#include "bubble_sort.h"

void bubble_sort(struct void_arr *arr, _Bool (*compare)(void *a, void *b))
{
    char *this = NULL;
    char *other = NULL;
    void *tmp = calloc (1, arr->smemb);

    _Bool done = 0;

    for (size_t i = 0; !done && i < arr->nmemb - 1; i++)
    {
        done = 1;

        for (size_t j = 0; j < arr->nmemb - i - 1; j++)
        {
            this = get_item(arr, j);
            other = get_item(arr, j + 1);

            if (compare(this, other))
            {
                done = 0;

                memcpy(tmp, this, arr->smemb);
                memcpy(this, other, arr->smemb);
                memcpy(other, tmp, arr->smemb);
            }
        }
    }

    free(tmp);
}

