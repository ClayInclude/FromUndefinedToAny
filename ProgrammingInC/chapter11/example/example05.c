/**
 * example05
 * @author Clay
 * @version V 1.0.0
 */

#include <stdio.h>

struct IntPtrs
{
    int *p1;
    int *p2;
};

int main(void)
{
    int i1 = 100, i2 = 0;
    struct IntPtrs pointers = {&i1, &i2};

    *pointers.p2 = -97;

    printf("i1 = %i, *pointers.p1 = %i\n", i1, *pointers.p1);
    printf("i2 = %i, *pointers.p2 = %i\n", i2, *pointers.p2);

    return 0;
}
