/**
 * practice02
 * @author Clay
 * @version V 1.0.0
 */

#include <stdio.h>

typedef enum Month
{
    january,
    february,
    march,
    april,
    may,
    june,
    july,
    august,
    september,
    october,
    november,
    december
} Month;

char *monthName[] =
    {
        "january", "february", "march", "april", "may", "june", "july", "august", "september",
        "october", "november", "december"
    };

char *getMonth(Month month);

int main(void)
{
    printf("%s", getMonth((Month)(december)));
}

char *getMonth(Month month)
{
    if (month < 0 || month > 11) return "";

    return monthName[month];
}
