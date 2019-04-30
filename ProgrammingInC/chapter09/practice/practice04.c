#include <math.h>
#include <stdio.h>

typedef struct date
{
    int year;
    int month;
    int day;
} date;

char const *diffDays(date const *d);

int main(void)
{
    date now = {0, 0, 0};

    printf("Enter a day:\n");
    scanf("%i%i%i", &now.year, &now.month, &now.day);

    printf("Day is %s.\n", diffDays(&now));

    return 0;
}

int _f(date const *d)
{
    if (d->month <= 2)
    {
        return d->year - 1;
    }
    else
    {
        return d->year;
    }
}

int _g(date const *d)
{
    if (d->month <= 2)
    {
        return d->month + 13;
    }
    else
    {
        return d->month + 1;
    }
}

int _n(date const *d)
{
    return 1461 * _f(d) / 4 + 153 * _g(d) / 5 + d->day;
}

char const *diffDays(date const *d)
{
    char const *day[7] = {"Sun", "Mon", "Tues", "Wed", "Thur", "Fri", "Sat"};

    return day[(_n(d) - 2) % 7];
}
