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
    struct time times[5] = {{11, 59, 59}, {12, 0, 0}, {1, 29, 59}, {23, 59, 59}, {19, 12, 27}};

    for (int i = 0; i < 5; ++i)
    {
        printf("Now is %.2i:%.2i:%.2i\n", times[i].hour, times[i].minute, times[i].seconds);
        updateSec(&times[i]);
        printf("Next sec is %.2i:%.2i:%.2i\n", times[i].hour, times[i].minute, times[i].seconds);
    }
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
