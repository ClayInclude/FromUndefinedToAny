/**
 * example02
 * @author Clay
 * @date 2020/2/26
 */

#include <stdio.h>

void testInplaceSwap(int x, int y);

void testReverseArray(int *array, int count);

int main(void)
{
    testInplaceSwap(0, 0);
    testInplaceSwap(0, 8);
    testInplaceSwap(-1, 0);
    testInplaceSwap(1, 3);
    testInplaceSwap(-1, -3);

    testReverseArray((int []){1, 7, 6, 8}, 4);
    testReverseArray((int []){1, 7, 6, 8, 2}, 5);

    return 0;
}

void inplaceSwap(unsigned int *x, unsigned int *y)
{
    *x = *x ^ *y;
    *y = *x ^ *y;
    *x = *x ^ *y;
}

void printArray(int *array, int count)
{
    for (int i = 0; i < count; ++i)
    {
        printf("%d", array[i]);

        if (i < count - 1)
        {
            printf(" ");
        }
    }

    printf("\n");
}

void reverseArray(unsigned int *array, int count)
{
    printArray((int *)array, count);

    for (int first = 0, last = count - 1; first < last; ++first, --last)
    {
        inplaceSwap(array + first, array + last);
    }

    printArray((int *)array, count);
}

void testInplaceSwap(int x, int y)
{
    printf("x: %d, y: %d\n", x, y);
    inplaceSwap((unsigned int *) &x, (unsigned int *) &y);
    printf("x: %d, y: %d\n", x, y);
}

void testReverseArray(int *array, int count)
{
    reverseArray((unsigned int *) array, count);
}
