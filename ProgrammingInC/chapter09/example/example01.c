#include <stdio.h>
#include <time.h>

struct Date
{
    int year;
    int month;
    int day;
};

int main(void)
{
    time_t t = time(NULL);
    struct Date today = {0, 0, 0};
    struct tm now;

    localtime_s(&now, &t);

    today.year = now.tm_year + 1900;
    today.month = now.tm_mon + 1;
    today.day = now.tm_mday;

    printf("Today's date is %i/%.2i/%.2i.\n", today.year, today.month, today.day);

    return 0;
}
