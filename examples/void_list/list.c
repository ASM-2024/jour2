#include "list.h"

static void list_free_item(struct list *item)
{
    free(item->data);
    free(item);
}

void list_free(struct list *list)
{
    struct list *next = NULL;

    for (; list; list = next)
    {
        next = list->next;
        // This list should only contain allocated instances of data types that
        // do not have allocated fields
        list_free_item(list);
    }
}

struct list *list_add(struct list *list, void *elem, size_t elem_size)
{
    // New list item
    struct list *new = calloc(1, sizeof(struct list));
    if (!new)
        return NULL;

    // We cannot dereference a void pointer so instead of doing janky casts left
    // and right we memcpy(3) the desired amount of bytes
    new->data = calloc(1, elem_size);
    memcpy(new->data, elem, elem_size);

    // Empty list
    if (!list)
        return new;

    // Create an iterator to keep the original pointer to the start of the list
    struct list *it = list;

    // Reach end of the list
    for (; it->next; it = it->next)
        continue;

    it->next = new;

    return list;
}

struct list *list_remove(struct list *list, size_t index)
{
    // EC: Empty list
    if (!list)
        return NULL;

    // Create an iterator to keep the original pointer to the start of the list
    struct list *it = list;

    // EC: First element
    if (!index)
    {
        it = it->next;
        list_free_item(list);
        return it;
    }

    // `i + 1' and not `index - 1' to avoid unsigned problems when index == 0
    for (size_t i = 0; i + 1 < index; i++, it = it->next)
        // `index' < 0 || `index' > count
        if (!it)
            return list;

    // `index' < count
    if (it->next)
    {
        struct list *removed = it->next;
        it->next = removed->next;
        list_free_item(removed);
    }

    // Return original pointer to enable function composition
    return list;
}

