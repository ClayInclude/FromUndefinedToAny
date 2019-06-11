/**
 * example09
 * @author Clay
 * @version V 1.0.0
 */

#include <stdio.h>

void exchange(int *pint1, int *pint2);

int main(void)
{
    int i1 = -5, i2 = 66;
    int *p1 = &i1, *p2 = &i2;

    printf("i1 = %i, i2 = %i\n", i1, i2);

    exchange(p1, p2);
    printf("i1 = %i, i2 = %i\n", i1, i2);

    exchange(&i1, &i2);
    printf("i1 = %i, i2 = %i\n", i1, i2);

    return 0;
}

void exchange(int *const pint1, int *const pint2)
{
    int temp = *pint1;
    *pint1 = *pint2;
    *pint2 = temp;
}
