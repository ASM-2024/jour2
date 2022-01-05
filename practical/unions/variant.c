#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "variant.h"

void variant_display(const struct variant *v)
{
    switch (v->type)
    {
    case TYPE_CHAR:
        printf("%c\n", v->value.char_v);
        break;
    case TYPE_FLOAT:
        printf("%f\n", v->value.float_v);
        break;
    case TYPE_INT:
        printf("%d\n", v->value.int_v);
        break;
    default:
        //here we use puts instead of printf(3) because puts(3) will 
        //print a string on the standard output and will print a \n at the end.
        //puts(3) only takes strings as argument, for further info
        //about puts(3), refer to the man page.
        puts(v->value.str_v);
    }
}

int variant_equal(const struct variant *first, const struct variant *second)
{
    //first we check that the types are the same in order to prevent comparing
    //values with different data types.
    //if the types are different we return 0 (false)
    if (first->type != second->type)
        return 0;

    switch (first->type)
    {
    case TYPE_CHAR:
        return first->value.char_v == second->value.char_v;
    case TYPE_FLOAT:
        return first->value.float_v == second->value.float_v;
    case TYPE_INT:
        return first->value.int_v == second->value.int_v;
    default:
        //we can create a function in order to compare the two strings
        //but I decided to use strcmp(3) from <string.h> instead.
        //for further info about strcmp(3), refer to the man page.
        return (strcmp(first->value.str_v, second->value.str_v) == 0);
    }
}

size_t variant_find(const struct variant *array, size_t len, enum type type,
                 union type_any value)
{
    size_t count = 0;

    for (size_t i = 0; i < len; i++)
    {
        if (array[i].type == type)
        {
            switch (type)
            {
            case TYPE_CHAR:
                if (value.char_v == array[i].value.char_v)
                    count++;
                break;
            case TYPE_FLOAT:
                if (value.float_v == array[i].value.float_v)
                    count++;
                break;
            case TYPE_INT:
                if (value.int_v == array[i].value.int_v)
                    count++;
                break;
            default:
                if (strcmp(value.str_v, array[i].value.str_v) == 0)
                    count++;
                break;
            }
        }
    }

    return count;
}

//here we create a subfunction for two things:
//1. doing the same thing multiple times
//2. avoiding having a big function (more than 25 lines) and having a
//more readable code.
//here the function just convert a variant into an int
static int variant_to_int(const struct variant *v)
{
    int int_v = 0;

    switch (v->type)
    {
    case TYPE_INT:
        int_v = v->value.int_v;
        break;
    case TYPE_FLOAT:
        int_v = v->value.float_v;
        break;
    case TYPE_CHAR:
        int_v = v->value.char_v;
        break;
    default:
        //atoi(3) converts a string into an int, for further info, refer to
        //the man page
        int_v = atoi(v->value.str_v);
        break;
    }
    
    return int_v;
}

int variant_is_sorted(const struct variant *array, size_t len)
{
    for (size_t i = 0; i < len - 1; i++)
    {
        //here we compare the two results of variant_to_int in order to know
        //if the array is sorted
        if (variant_to_int(&(array[i])) > variant_to_int(&(array[i + 1])))
            return 0; 
    }

    return 1;
}

int variant_sum(const struct variant *array, size_t len)
{
    int sum = 0;
    int tmp = 0;
    
    for (size_t i = 0; i < len; i++)
    {
        switch (array[i].type)
        {
        case TYPE_INT:
            sum += array[i].value.int_v;
            break;
        case TYPE_FLOAT:
            tmp = array[i].value.float_v;
            sum += tmp;
            break;
        case TYPE_CHAR:
            tmp = array[i].value.char_v;
            sum += tmp;
            break;
        default:
            sum += atoi(array[i].value.str_v);
            break;
        }
    }

    return sum;
}
