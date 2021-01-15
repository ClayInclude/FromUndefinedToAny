/**
 * Signal
 * @author Clay
 * @date 2021/1/14
 */

#include "csapp.h"
#include "stdbool.h"

void handler1(int sig);

void handler2(int sig);

int main(void)
{
    if (signal(SIGCHLD, handler2) == SIG_ERR)
    {
        unix_error("signal error");
    }

    for (int i = 0; i < 3; ++i)
    {
        if (Fork() == 0)
        {
            printf("Hello from %d\n", getpid());
            Sleep(1);

            exit(0);
        }
    }

    int n;
    char buffer[128];

    if ((n = read(STDIN_FILENO, buffer, 128)) < 0)
    {
        unix_error("read");
    }

    printf("Parent processing input\n");

    while (true)
    {
        ;
    }

    exit(0);
}

void handler2(int sig)
{
    int oldErrno = errno;

    while  (waitpid(-1, NULL, 0) >= 0)
    {
        Sio_puts("Handler reaped child\n");

    }

    if (errno != ECHILD)
    {
        Sio_error("wait pid error\n");
    }

    Sleep(1);

    errno = oldErrno;
}

void handler1(int sig)
{
    int oldErrno = errno;

    if (waitpid(-1, NULL, 0) < 0)
    {
        Sio_error("wait pid error\n");
    }

    Sio_puts("Handler reaped child\n");

    Sleep(1);

    errno = oldErrno;
}
