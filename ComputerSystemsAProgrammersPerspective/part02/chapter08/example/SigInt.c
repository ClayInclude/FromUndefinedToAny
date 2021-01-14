/**
 * SigInt
 * @author Clay
 * @date 2021/1/14
 */

#include "csapp.h"

void sigIntHandler(int sig);

int main(void)
{
    if (signal(SIGINT, sigIntHandler) == SIG_ERR)
    {
        unix_error("signal error");
    }

    pause();

    return 0;
}

void sigIntHandler(int sig)
{
    Sio_puts("Caught SIGINT.\n");

    _exit(0);
}
