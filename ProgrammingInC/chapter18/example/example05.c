/**
 * example05
 * @author Clay
 * @version V 1.0.0
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct Date
{
    int month;
    int day;
    int year;
}Date;

Date foo(Date x);

int main(void)
{
    Date today = {10, 11, 2004};
    int array[5] = {1, 2, 3, 4, 5};
    Date *newDate = NULL;
    char const *str = "test string";
    int i = 3;

    newDate = (Date *) malloc(sizeof(Date));
    *newDate = (Date){11, 15, 2004};

    today = foo(today);
    free(newDate);

    return 0;
}

Date foo(Date x)
{
    ++x.day;

    return x;
}
