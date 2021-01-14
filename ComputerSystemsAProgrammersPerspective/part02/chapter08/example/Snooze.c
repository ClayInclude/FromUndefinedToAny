/**
 * Snooze
 * @author Clay
 * @date 2021/1/11
 */

#include "csapp.h"

unsigned int snooze(unsigned int secs);
void sigIntHandler(int sig);

int main(void)
{
    if (signal(SIGINT, sigIntHandler) == SIG_ERR)
    {
        unix_error("signal error");
    }

    snooze(5);
}

unsigned int snooze(unsigned int secs)
{
    unsigned int remain = sleep(secs);

    printf("Slept for %d of %d secs\n", secs - remain, secs);

    return remain;
}

void sigIntHandler(int sig)
{
    kill(0, SIGCONT);
}
