/**
 * Snooze
 * @author Clay
 * @date 2021/1/11
 */

#include "../../../include/csapp.h"

unsigned int snooze(unsigned int secs);

int main(void)
{
    snooze(1);
    snooze(2);
    snooze(3);
}

unsigned int snooze(unsigned int secs)
{
    unsigned int remain = sleep(secs);

    printf("Slept for %d of %d secs\n", secs - remain, secs);

    return remain;
}
