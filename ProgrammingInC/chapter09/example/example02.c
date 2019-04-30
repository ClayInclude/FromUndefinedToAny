#include <stdbool.h>
#include <stdio.h>

bool isLeapYear(int year);

struct time
{
    int year;
    int month;
    int day;
};

int const months[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main(void)
{
    struct time next = {0, 0, 0};

    printf("Enter today's date (yyyy mm dd)\n");
    scanf("%i%i%i", &next.year, &next.month, &next.day);

    if (next.year < 1)
    {
        printf("Illegal year!\n");

        return 1;
    }
    if (next.month > 12 || next.month < 1)
    {
        printf("Illegal month!\n");

        return 2;
    }

    int monthDay = months[next.month - 1];

    if (isLeapYear(next.year) && next.month == 2)
    {
        ++monthDay;
    }

    if (next.day > monthDay || next.day < 1)
    {
        printf("Illegal day!\n");

        return 3;
    }

    if (next.day != monthDay)
    {
        ++next.day;
    }
    else
    {
        next.day = 1;

        if (next.month != 12)
        {
            ++next.month;
        }
        else
        {
            next.month = 1;
            ++next.year;
        }
    }

    printf("Next day is %i/%.2i/%.2i.\n", next.year, next.month, next.day);

    return 0;
}

bool isLeapYear(int year)
{
    return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
}
