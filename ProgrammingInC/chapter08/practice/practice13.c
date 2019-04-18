#include <stdbool.h>
#include <stdio.h>

bool order = true;

void quickSort(int *array, int low, int high);

int main(void)
{
    int array[16] = {34, -5, 6, 0, 12, 100, 56, 22, 44, -3, -9, 12, 17, 22, 6, 11};

    order = true;

    quickSort(array, 0, 16);

    for (int i = 0; i < 16; ++i)
    {
        printf("%i ", array[i]);
    }

    printf("\n");


    return 0;
}

bool decide(int x, int y)
{
    if (order)
    {
        return x < y;
    }
    else
    {
        return x > y;
    }
}

void swap(int *x, int *y)
{
    int temp = *x;

    *x = *y;
    *y = temp;
}

int partition(int *array, int low, int high)
{
    int index = low - 1;
    int p = array[high - 1];

    for (int i = low; i < high - 1; ++i)
    {
        if (decide(array[i], p))
        {
            swap(array + i, array + (++index));
        }
    }

    swap(array + high - 1, array + (++index));

    return index;
}

void quickSort(int *array, int low, int high)
{
    if (low >= high)
    {
        return;
    }

    int q = partition(array, low, high);
    quickSort(array, low, q - 1);
    quickSort(array, q + 1, high);

    return;
}
