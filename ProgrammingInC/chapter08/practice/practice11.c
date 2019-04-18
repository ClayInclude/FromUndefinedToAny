#include <stdio.h>

double arraySum(double *array, int len);

int main(void)
{
    double array[] = {3, 5, 64, 12, 34, 22222};

    printf("arraySum = %lf\n", arraySum(array, 6));

    return 0;
}

double arraySum(double *array, int len)
{
    double sum = 0;

    for (int i = 0; i < len; ++i)
    {
        sum += *(array + i);
    }

    return sum;
}
