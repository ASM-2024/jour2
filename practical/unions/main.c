#include <assert.h>
#include <err.h>
#include <stdlib.h>
#include <stdio.h>

#include "variant.h"

static void *xmalloc(size_t size)
{
    void *tmp = malloc(size);
    if (!tmp)
        errx(1, "Error while allocating memory");

    return tmp;
}

static void variant_array_print(struct variant *v, size_t len)
{
    for (size_t i = 0; i < len; i++)
    {
        printf("v[%lu] = ", i);
        variant_display(&(v[i]));    
    }
}

int main(void)
{
    struct variant *v = xmalloc(8 * sizeof(struct variant));

    v[0].type = TYPE_INT;
    v[0].value.int_v = 10;
    v[1].type = TYPE_FLOAT;
    v[1].value.float_v = 10.0;
    v[2].type = TYPE_STRING;
    v[2].value.str_v = "10";
    v[3].type = TYPE_CHAR;
    v[3].value.char_v = 10;
    v[4].type = TYPE_INT;
    v[4].value.int_v = 10;
    v[5].type = TYPE_FLOAT;
    v[5].value.float_v = 14.4;
    v[6].type = TYPE_STRING;
    v[6].value.str_v = "53";
    v[7].type = TYPE_CHAR;
    v[7].value.char_v = 100;

    variant_array_print(v, 8);

    //assert(3) check if the assertion is good, if not it will stop the program
    //for further info, refer to the man page
    assert(variant_equal(&(v[0]), &(v[4])));
    assert(variant_find(v, 8, TYPE_INT, v->value) == 2);
    assert(variant_is_sorted(v, 8));
    assert(variant_sum(v, 8) == 217);

    free(v);
}
