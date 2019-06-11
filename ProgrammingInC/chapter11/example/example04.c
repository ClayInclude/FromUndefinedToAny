/**
 * example04
 * @author Clay
 * @version V 1.0.0
 */

#include <stdio.h>

struct Date
{
    int year;
    int month;
    int day;
};

int main(void)
{
    struct Date today = {0, 0, 0};
    struct Date *datePtr = &today;

    datePtr->year = 2004;
    datePtr->month = 9;
    datePtr->day = 25;

    printf("Today's date is %04i/%02i/%02i.\n", datePtr->year, datePtr->month, datePtr->day);

    return 0;
}
