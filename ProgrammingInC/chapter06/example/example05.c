#include <stdbool.h>
#include <stdio.h>

bool isLeapYear(int year);

int main(void)
{
    int year = 0;

    printf("Enter the year to be tested:\n");
    scanf("%i", &year);

    if (isLeapYear(year))
    {
        printf("It's a leap year.\n");
    }
    else
    {
        printf("It's not a leap year.\n");
    }

    return 0;
}

bool isLeapYear(int year)
{
    return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
}
