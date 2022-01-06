#include <stdio.h>

#include "macros.h"

int main(void)
{
    DECLARE_AND_SET(float, asm, 4.2);

    printf("asm = %f\n", asm);
    printf("*ptr_asm = %f\n", *ptr_asm);
    printf("str_asm = %s\n", str_asm);

    return 0;
}
