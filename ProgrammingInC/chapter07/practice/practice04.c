#include <stdio.h>

int main(void)
{
    double array[10] = {0};
    double average = 0;

    for (int i = 0; i < 10; ++i)
    {
        array[i] = i * 9.99999999999;
        average += array[i];
    }

    average /= 10;
    printf("Average of array = %lf\n", average);

    return 0;
}
