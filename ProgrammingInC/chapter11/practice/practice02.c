/**
 * practice02
 * @author Clay
 * @version V 1.0.0
 */

#include <stdio.h>

typedef struct Entry
{
    int value;
    struct Entry *next;
} Entry;

void insertEntry(Entry *value, Entry *locate);
void removeEntry(Entry *locate);
void printEntry(Entry *head);

int main(void)
{
    Entry value = {200, NULL}, head = {0, NULL};
    Entry e[3] = {
        {100, NULL},
        {300, NULL},
        {400, NULL}
    };

    head.next = e;
    e[0].next = e + 1;
    e[1].next = e + 2;

    printEntry(&head);

    insertEntry(&value, e);
    printEntry(&head);

    removeEntry(e);
    printEntry(&head);

    removeEntry(e);
    printEntry(&head);

    return 0;
}

void insertEntry(Entry *value, Entry *locate)
{
    if (!value || !locate) return;

    value->next = locate->next;
    locate->next = value;
}

void removeEntry(Entry *locate)
{
    if (!locate || !locate->next) return;

    locate->next = locate->next->next;
}

void printEntry(Entry *head)
{
    if (!head) return;

    Entry *ptr = head->next;

    while (ptr)
    {
        printf("%i\n", ptr->value);
        ptr = ptr->next;
    }
}
