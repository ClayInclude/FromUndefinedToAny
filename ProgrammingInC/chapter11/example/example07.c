/**
 * example07
 * @author Clay
 * @version V 1.0.0
 */

#include <stdio.h>

struct Entry
{
    int value;
    struct Entry *next;
};

int main(void)
{
    struct Entry n3 = {300, NULL};
    struct Entry n2 = {200, &n3};
    struct Entry n1 = {100, &n2};
    struct Entry *list_pointer = &n1;

    while (list_pointer)
    {
        printf("%i\n", list_pointer->value);
        list_pointer = list_pointer->next;
    }

    return 0;
}
