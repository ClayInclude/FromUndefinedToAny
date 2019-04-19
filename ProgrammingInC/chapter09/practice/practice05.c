#include <stdbool.h>
#include <stdio.h>

typedef struct
{
    struct
    {
        int year;
        int month;
        int day;
    } date;

    struct
    {
        int hour;
        int minute;
        int second;
    } time;
} dateAndTime;

void updateSec(dateAndTime *t);

int main(void)
{
    dateAndTime dt = {{0, 0, 0}, {0, 0, 0}};

    printf("Enter your Time(yyyy mm dd hh:mm:ss\n");
    scanf_s("%i%i%i%i:%i:%i", &dt.date.year, &dt.date.month, &dt.date.day, &dt.time.hour, &dt.time.minute, &dt.time.second);

    updateSec(&dt);

    printf("Next second is :%i/%i/%i/ %.2i:%.2i:%.2i\n", dt.date.year, dt.date.month, dt.date.day, dt.time.hour, dt.time.minute, dt.time.second);

    return 0;
}

bool isLeapYear(int year)
{
    return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
}

int getNumberOfDays(dateAndTime *d)
{
    int const months[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (d->date.month != 2 || !isLeapYear(d->date.year))
    {
        return months[d->date.month - 1];
    }
    else
    {
        return months[1] + 1;
    }
}

void updateTime(dateAndTime *d)
{
    int monthDay = getNumberOfDays(d);

    if (d->date.day != monthDay)
    {
        ++d->date.day;
    }
    else
    {
        d->date.day = 1;

        if (d->date.month != 12)
        {
            ++d->date.month;
        }
        else
        {
            d->date.month = 1;
            ++d->date.year;
        }
    }
}

void updateSec(dateAndTime *t)
{
    if (t->time.second != 59)
    {
        ++t->time.second;
    }
    else
    {
        t->time.second = 0;

        if (t->time.minute != 59)
        {
            ++t->time.minute;
        }
        else
        {
            t->time.minute = 0;

            if (t->time.hour != 23)
            {
                ++t->time.hour;
            }
            else
            {
                t->time.hour = 0;
                updateTime(t);
            }
        }
    }
}
