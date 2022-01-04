#ifndef VARIANT_H
#define VARIANT_H

#include <stddef.h>

enum type
{
    TYPE_INT,
    TYPE_FLOAT,
    TYPE_CHAR,
    TYPE_STRING
};

union type_any
{
    int int_v;
    float float_v;
    char char_v;
    const char *str_v;
};

struct variant
{
    enum type type;
    union type_any value;
};

void variant_display(const struct variant *v);
int variant_equal(const struct variant *first, const struct variant *second);
size_t variant_find(const struct variant *array, size_t len, enum type type,
                 union type_any value);
int variant_is_sorted(const struct variant *array, size_t len);
int variant_sum(const struct variant *array, size_t len);

#endif
