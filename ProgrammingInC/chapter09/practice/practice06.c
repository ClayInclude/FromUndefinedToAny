#include <stdbool.h>
#include <stdio.h>

#define newTime(_year, _month, _day) (time) { .year = _year, .month = _month, .day = _day }

typedef struct
{
    int year;
    int month;
    int day;
} time;

time updateTime(time d);

int main(void)
{
    time next = updateTime(newTime(2018, 12, 31));

    printf("Next day is %i/%.2i/%.2i.\n", next.year, next.month, next.day);

    return 0;
}

bool isLeapYear(int year)
{
    return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
}

int getNumberOfDays(time d)
{
    int const months[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (d.month != 2 || !isLeapYear(d.year))
    {
        return months[d.month - 1];
    }
    else
    {
        return months[1] + 1;
    }
}

time updateTime(time d)
{
    int monthDay = getNumberOfDays(d);

    if (d.day != monthDay)
    {
        ++d.day;
    }
    else
    {
        d.day = 1;

        if (d.month != 12)
        {
            ++d.month;
        }
        else
        {
            d.month = 1;
            ++d.year;
        }
    }

    return d;
}
