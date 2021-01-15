/**
 * SignalProb0
 * @author Clay
 * @date 2021/1/15
 */

#include <stdbool.h>
#include "csapp.h"

volatile long int counter = 2;

void handler1(int sig);

int main(void )
{
    pid_t pid;

    sigset_t mask, preMask;

    printf("%ld", counter);
    fflush(stdout);

    signal(SIGUSR1, handler1);

    if ((pid = Fork()) == 0)
    {
        while (true)
        {
            ;
        }
    }

    Kill(pid, SIGUSR1);

    Waitpid(-1, NULL, 0);

    Sigfillset(&mask);
    Sigprocmask(SIG_BLOCK, &mask, &preMask);
    printf("%ld", ++counter);
    Sigprocmask(SIG_SETMASK, &preMask, NULL);

    exit(0);
}

void handler1(int sig)
{
    sigset_t mask, preMask;

    Sigfillset(&mask);
    Sigprocmask(SIG_BLOCK, &mask, &preMask);
    Sio_putl(--counter);
    Sigprocmask(SIG_SETMASK, &preMask, NULL);

    _exit(0);
}
