/**
 * practice11
 * @author Clay
 * @version V 1.0.0
 */

#include <stdbool.h>
#include <stdio.h>

struct time
{
    int year;
    int month;
    int day;
};

int checkTime(struct time *d);
void updateTime(struct time *d);

int main(void)
{
    struct time next = {0, 0, 0};

    printf("Enter today's date (yyyy mm dd)\n");
    scanf("%i%i%i", &next.year, &next.month, &next.day);

    int errcode = checkTime(&next);
    if (errcode)
    {
        return errcode;
    }

    updateTime(&next);

    printf("Next day is %i/%.2i/%.2i.\n", next.year, next.month, next.day);

    return 0;
}

bool isLeapYear(int year)
{
    return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
}

int getNumberOfDays(struct time *d)
{
    int const months[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (d->month != 2 || !isLeapYear(d->year))
    {
        return months[d->month - 1];
    }
    else
    {
        return months[1] + 1;
    }
}

int checkTime(struct time *d)
{
    if (d->year < 1)
    {
        printf("Illegal year!\n");

        return 1;
    }
    if (d->month > 12 || d->month < 1)
    {
        printf("Illegal month!\n");

        return 2;
    }

    int monthDay = getNumberOfDays(d);

    if (d->day > monthDay || d->day < 1)
    {
        printf("Illegal day!\n");

        return 3;
    }

    return 0;
}

void updateTime(struct time *d)
{
    int monthDay = getNumberOfDays(d);

    if (d->day != monthDay)
    {
        ++d->day;
    }
    else
    {
        d->day = 1;

        if (d->month != 12)
        {
            ++d->month;
        }
        else
        {
            d->month = 1;
            ++d->year;
        }
    }
}
