/**
 * practice08
 * @author Clay
 * @version V 1.0.0
 */

#include <stdio.h>

void sort3(int *x, int *y, int *z);

int main(void)
{
    int x = 0, y = 1, z = 2;

    sort3(&x, &y, &z);
    printf("%i, %i, %i\n", x, y, z);

    x = 0, y = 2, z = 1;
    sort3(&x, &y, &z);
    printf("%i, %i, %i\n", x, y, z);

    x = 1, y = 0, z = 2;
    sort3(&x, &y, &z);
    printf("%i, %i, %i\n", x, y, z);

    x = 1, y = 2, z = 0;
    sort3(&x, &y, &z);
    printf("%i, %i, %i\n", x, y, z);

    x = 2, y = 0, z = 1;
    sort3(&x, &y, &z);
    printf("%i, %i, %i\n", x, y, z);

    x = 2, y = 1, z = 0;
    sort3(&x, &y, &z);
    printf("%i, %i, %i\n", x, y, z);

    return 0;
}

void swap(int *x, int *y)
{
    int temp = *x;

    *x = *y;
    *y = temp;
}

void sort3(int *x, int *y, int *z)
{
    if (*x > *y) swap(x, y);
    if (*x > *z) swap(x, z);
    if (*y > *z) swap(y, z);
}
