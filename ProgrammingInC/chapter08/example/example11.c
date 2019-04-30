#include <stdio.h>

void multiplyBy2(float array[], int n);

int main(void)
{
    float floatValues[4] = {1.2f, -3.7f, 6.2f, 8.55f};

    multiplyBy2(floatValues, 4);

    for (int i = 0; i < 4; ++i)
    {
        printf("%.2f ", floatValues[i]);
    }

    printf("\n");

    return 0;
}

void multiplyBy2(float *array, int n)
{
    for (int i = 0; i < n; ++i)
    {
        array[i] *= 2;
    }
}
