/**
 * example08
 * @author Clay
 * @version V 1.0.0
 */

#include <stdio.h>

void test(int *int_pointer);

int main(void)
{
    int i = 50;
    int *p = &i;

    printf("Before the call to test i = %i\n", i);
    test(p);
    printf("After the call to test i = %i\n", i);

    return 0;
}

void test(int *int_pointer)
{
    *int_pointer = 100;
}
