#include <stdio.h>
#include <err.h>

#include "list.h"

// Macros will be detailed a bit later, just know that this replaces every
// instance of the text "TYPE" under it with the string given on the right,
// which in this case is the desired type of the elements in the list
#define TYPE size_t

// This function is not generic and only really works for lists containing
// size_t items. It could be made in a generic fashion but it would require a
// lot more code and a change in the structure so it is not worth it to do so
// here
void list_print_size_t(struct list *list)
{
    size_t *data;

    printf("[");
    for (struct list *it = list; it; it = it->next)
    {
        data = list->data;
        printf("%s%lu%s", it != list ? " " : "", *data, it->next ? ", " : "");
    }
    printf("]\n");
}

int main(int argc, char **argv)
{
    size_t len = 10;

    if (argc > 2)
        errx(1, "Usage: %s [LENGTH]\n", argv[0]);
    else if (argc == 2)
        len = strtoul(argv[1], NULL, 10);

    // Empty list
    struct list *list = NULL;

    // Here we only add items of a single type for simplicity's sake but
    // because we're using void pointers we could add void pointers to other
    // data types, although in our implementation we would have no way to tell
    // what type something is
    for (size_t i = 0; i < len; i++)
    {
        TYPE *data = calloc(1, sizeof(TYPE));
        if (!data)
            errx(1, "Failed to allocate sufficient memory");

        list = list_add(list, data, sizeof(TYPE));
        free(data);
    }

    list_print_size_t(list);

    // Example of function composition, using the returned pointer
    list = list_remove(list_remove(list, 1), 3);

    list_print_size_t(list);

    list_free(list);

    return 0;
}
