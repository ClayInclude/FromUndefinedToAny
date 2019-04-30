#include <math.h>
#include <stdio.h>

typedef struct date
{
    int year;
    int month;
    int day;
} date;

int diffDays(date const *from, date const *to);

int main(void)
{
    date from = {0, 0, 0}, to = {0, 0, 0};

    printf("Enter two days:\n");
    scanf("%i%i%i", &from.year, &from.month, &from.day);
    scanf("%i%i%i", &to.year, &to.month, &to.day);

    printf("DiffDays is %i.\n", diffDays(&from, &to));

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

int diffDays(date const *from, date const *to)
{
    return abs(_n(from) - _n(to));
}
