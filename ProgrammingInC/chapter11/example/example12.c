/**
 * example12
 * @author Clay
 * @version V 1.0.0
 */

#include <stdio.h>

int arraySum(int const *array, int n);

int main(void)
{
    int values[10] = {3, 7, -9, 3, 6, -1, 7, 9, 1, -5};

    printf("The sum is %i\n", arraySum(values, 10));
    return 0;
}

int arraySum(int const *array, int const n)
{
    if (!array || n <= 0)
    {
        return 0;
    }

    int sum = 0;

    for (int const *end = array + n; array < end; ++array)
    {
        sum += *array;
    }

    return sum;
}
