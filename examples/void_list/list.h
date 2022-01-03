// "Include guard" that will be explained later
#ifndef LIST_H
#define LIST_H

// Contains calloc(3) and the definition of the size_t type among other things
#include <stdlib.h>
// Contains memcpy(3) among other things
#include <string.h>

struct list
{
    struct list *next;
    void *data;
};

void list_free(struct list *list);
struct list *list_add(struct list *list, void *elem, size_t elem_size);
struct list *list_remove(struct list *list, size_t index);

#endif
