/**
 * example03
 * @author Clay
 * @version V 1.0.0
 */

#include <stdio.h>

int main(void)
{
    int i1 = 5;
    int *p1 = &i1;
    int i2 = *p1 / 2 + 10;
    int *p2 = p1;

    printf("i1 = %i, i2 = %i, *p1 = %i, *p2 = %i\n", i1, i2, *p1, *p2);

    return 0;
}
