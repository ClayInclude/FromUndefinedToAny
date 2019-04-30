#include <stdio.h>

void quickSort(int *array, int low, int high);

int main(void)
{
    int array[16] = {34, -5, 6, 0, 12, 100, 56, 22, 44, -3, -9, 12, 17, 22, 6, 11};

    quickSort(array, 0, 16);

    for (int i = 0; i < 16; ++i)
    {
        printf("%i ", array[i]);
    }

    printf("\n");

    return 0;
}

void swap(int *x, int *y)
{
    int temp = *x;

    *x = *y;
    *y = temp;
}

int partition(int *array, int low, int high)
{
    int p = array[high - 1];
    int i = low - 1;

    for (int j = low; j < high - 1; ++j)
    {
        if (array[j] < p)
        {
            ++i;
            swap(array + i, array + j);
        }
    }

    swap(array + i + 1, array + high - 1);

    return i + 1;
}

void quickSort(int *array, int low, int high)
{
    if (low > high - 1)
    {
        return;
    }

    int p = partition(array, low, high);

    quickSort(array, low, p - 1);
    quickSort(array, p + 1, high);
}
