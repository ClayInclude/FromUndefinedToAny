/**
 * SigSuspend
 * @author Clay
 * @date 2021/1/22
 */

#include <stdbool.h>
#include "csapp.h"

volatile sig_atomic_t pid;

void sigChildHandler(int signal)
{
    int oldErrno = errno;

    pid = waitpid(-1, NULL, 0);

    errno = oldErrno;
}

void sigIntHandler(int signal)
{

}

int main(int argc, char **argv)
{
    sigset_t mask, pre;

    Signal(SIGCHLD, sigChildHandler);
    Signal(SIGINT, sigIntHandler);

    Sigemptyset(&mask);
    Sigaddset(&mask, SIGCHLD);

    while (true)
    {
        Sigprocmask(SIG_BLOCK, &mask, &pre);

        if (Fork() == 0)
        {
            exit(0);
        }

        pid = 0;

        while (!pid)
        {
            sigsuspend(&pre);
        }

        Sigprocmask(SIG_SETMASK, &pre, NULL);

        printf(".\n");
    }

    exit(0);
}
