#include <stdio.h>

struct time
{
    int hour;
    int minute;
    int seconds;
};

void updateSec(struct time *t);

int main(void)
{
    struct time now = {0, 0, 0};

    printf("Enter the time (hh:mm:ss)\n");
    scanf_s("%i:%i:%i", &now.hour, &now.minute, &now.seconds);

    if (now.hour > 23 || now.hour < 1 || now.minute > 59 || now.minute < 1 || now.seconds > 59 || now.seconds < 1)
    {
        printf("Illegal Time!\n");
        return 1;
    }

    updateSec(&now);

    printf("Next sec is %.2i:%.2i:%.2i\n", now.hour, now.minute, now.seconds);

    return 0;
}

void updateSec(struct time *t)
{
    if (t->seconds != 59)
    {
        ++t->seconds;
    }
    else
    {
        t->seconds = 0;

        if (t->minute != 59)
        {
            ++t->minute;
        }
        else
        {
            t->minute = 0;

            if (t->hour != 23)
            {
                ++t->hour;
            }
            else
            {
                t->hour = 0;
            }
        }
    }
}
