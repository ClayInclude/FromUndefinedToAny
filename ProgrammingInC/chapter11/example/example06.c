/**
 * example06
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

    int i = n1.next->value;

    printf("i = %i.\n", i);
    printf("n2.next->value = %i.\n", n2.next->value);
}
