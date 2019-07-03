/**
 * example01
 * @author Clay
 * @version V 1.0.0
 */

#include <stdio.h>

int main(void)
{
    typedef enum Month
    {
        january = 1,
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
    }Month;

    Month month;
    int days;
    printf("Enter month number: ");
    scanf("%i", &month);

    switch (month)
    {
        case january:
        case march:
        case may:
        case july:
        case august:
        case october:
        case december:
            days = 31;
            break;
        case april:
        case june:
        case september:
        case november:
            days = 30;
            break;
        case february:
            days = 28;
            break;
        default:
            printf("bad month number\n");
            days = 0;
            break;
    }

    if (days)
    {
        printf("Number of days is %i\n", days);
    }

    if (month == february)
    {
        printf("...or 29 if it's a leap year\n");
    }

    return 0;
}
