/**
 * practice05
 * @author Clay
 * @version V 1.0.0
 */

#include <stdio.h>
#include <stdbool.h>

typedef struct Entry
{
    int value;
    struct Entry *pre;
    struct Entry *next;
} Entry;

void insertEntry(Entry *value, Entry *locate);
void removeEntry(Entry *locate);
void printEntry(Entry const *head);

int main(void)
{
    Entry value = {200, NULL, NULL};
    Entry e[3] = {
        {100, NULL, NULL},
        {300, NULL, NULL},
        {400, NULL, NULL}
    };

    e[0].pre = e + 2;
    e[1].pre = e;
    e[2].pre = e + 1;

    e[0].next = e + 1;
    e[1].next = e + 2;
    e[2].next = e;

    printEntry(e);

    insertEntry(&value, e);
    printEntry(e);

    removeEntry(e + 1);
    printEntry(e);

    return 0;
}

void insertEntry(Entry *value, Entry *locate)
{
    if (!value || !locate) return;

    value->pre = locate;
    value->next = locate->next;
    locate->next->pre = value;
    locate->next = value;
}

void removeEntry(Entry *locate)
{
    if (!locate) return;

    locate->pre->next = locate->next;
    locate->next->pre = locate->pre;
}

void printEntry(Entry const *head)
{
    bool flag = false;
    Entry const *ptr = head;

    while (ptr)
    {
        if (ptr == head)
        {
            if (flag)
            {
                break;
            }
            else
            {
                flag = true;
            }
        }

        printf("%i\n", ptr->value);
        ptr = ptr->next;
    }
}
