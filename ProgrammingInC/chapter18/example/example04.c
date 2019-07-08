/**
 * example04
 * @author Clay
 * @version V 1.0.0
 */

#include <stdio.h>

int main(void)
{
    const int data[5] = {1, 2, 3, 4, 5};
    int i = 0, sum = 0;

    for (; i >= 0; ++i)
    {
        sum += data[i];
    }

    printf("sum = %i\n", sum);

    return 0;
}
