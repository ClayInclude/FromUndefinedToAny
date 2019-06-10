/**
 * example01
 * @author Clay
 * @version V 1.0.0
 */

#include <stdio.h>

int main(void)
{
    int count = 10, x = 0;
    int *int_pointer = NULL;

    int_pointer = &count;
    x = *int_pointer;

    printf("count = %i, x = %i\n", count, x);

    return 0;
}
