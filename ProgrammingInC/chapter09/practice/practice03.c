#include <stdio.h>

typedef struct
{
    int hour;
    int minute;
    int second;
} time;

time diffTime(time const *from, time const *to);

int main(void)
{
    time from = {5, 30, 59}, to = {0, 0, 0};

    time diff1 = diffTime(&from, &to);
    time diff2 = diffTime(&to, &from);
    time diff3 = diffTime(&from, &from);
    printf("from -> to: %.2i:%.2i:%.2i\n", diff1.hour, diff1.minute, diff1.second);
    printf("from -> to: %.2i:%.2i:%.2i\n", diff2.hour, diff2.minute, diff2.second);
    printf("from -> to: %.2i:%.2i:%.2i\n", diff3.hour, diff3.minute, diff3.second);

    return 0;
}

time toStruct(int second)
{
    int sec = second % 60;

    second /= 60;
    int minute = second % 60;
    int hour = second / 60;

    return (time) {.hour = hour, .minute = minute, .second = sec};
}

int toSecond(time const *t)
{
    return t->hour * 3600 + t->minute * 60 + t->second;
}

time diffTime(time const *from, time const *to)
{
    // int fromSec = toSecond(from), toSec = toSecond(to);

    int diffSec = toSecond(from) - toSecond(to);

    diffSec = diffSec >= 0 ? diffSec : diffSec + 86400;

    return toStruct(diffSec);
}
