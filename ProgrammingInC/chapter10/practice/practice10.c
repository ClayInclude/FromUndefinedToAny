/**
 * practice10
 * @author Clay
 * @version 2019/5/10
 */

#include <stdio.h>
#include <string.h>

typedef struct
{
    char word[15];
    char definition[50];
} entry;

void quickSort(entry *array, int low, int high);
void printEntry(entry *array, int length);

entry dictionary[] =
    {
        {"aardvark", "a burrowing African mammal"},
        {"abyss",    "a bottomless pit"},
        {"acumen",   "mentally sharp; keen"},
        {"addle",    "to become confused"},
        {"aerie",    "a high nest"},
        {"affix",    "to append; attach"},
        {"agar",     "a jelly made from seaweed"},
        {"ahoy",     "a nautical call of greeting"},
        {"aigrette", "an ornamental cluster of feathers"},
        {"ajar",     "partially opened"}
    };

int main(void)
{
    printEntry(dictionary, 10);
    quickSort(dictionary, 0, 10);
    printEntry(dictionary, 10);

    return 0;
}

void swap(entry *x, entry *y)
{
    entry temp = *x;

    *x = *y;
    *y = temp;
}

int partition(entry *array, int low, int high)
{
    entry p = array[high - 1];
    int i = low - 1;

    for (int j = low; j < high - 1; ++j)
    {
        if (strcmp(p.definition, array[j].definition) > 0)
        {
            ++i;
            swap(array + i, array + j);
        }
    }

    swap(array + i + 1, array + high - 1);

    return i + 1;
}

void quickSort(entry *array, int low, int high)
{
    if (low > high - 1)
    {
        return;
    }

    int p = partition(array, low, high);

    quickSort(array, low, p - 1);
    quickSort(array, p + 1, high);
}

void printEntry(entry *array, int length)
{
    for (int i = 0; i < length; ++i)
    {
        printf("%s: %s\n", array[i].word, array[i].definition);
    }
}
