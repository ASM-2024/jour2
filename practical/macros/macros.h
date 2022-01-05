#ifndef MACROS_H
#define MACROS_H

#define DECLARE_AND_SET(TYPE, NAME, VALUE)  \
TYPE NAME = VALUE;                          \
TYPE *ptr_ ## NAME = &NAME;                 \
char *str_ ## NAME = #VALUE;

#endif
