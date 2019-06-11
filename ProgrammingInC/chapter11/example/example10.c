/**
 * example10
 * @author Clay
 * @version V 1.0.0
 */

#include <stdio.h>

typedef struct Entry
{
    int value;
    struct Entry *next;
} Entry;

Entry const *findEntry(Entry const *listPtr, int match);

int main(void)
{
    Entry n3 = {300, NULL}, n2 = {200, &n3}, n1 = {100, &n2};
    Entry const *listPtr = NULL, *listStart = &n1;

    int search = 0;

    printf("Enter value to locate: ");
    scanf("%i", &search);

    listPtr = findEntry(listStart, search);
    if (listPtr)
    {
        printf("Found %i.\n", listPtr->value);
    }
    else
    {
        printf("Not found.\n");
    }

    return 0;
}

Entry const *findEntry(Entry const *listPtr, int match)
{
    while (listPtr)
    {
        if (listPtr->value == match)
        {
            return listPtr;
        }
        else
        {
            listPtr = listPtr->next;
        }
    }

    return NULL;
}
