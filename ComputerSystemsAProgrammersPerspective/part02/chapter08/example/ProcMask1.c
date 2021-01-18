/**
 * ProcMask1
 * @author Clay
 * @date 2021/1/18
 */

#include <stdbool.h>
#include "csapp.h"

#define MAX_PID_LIST 10

pid_t pidList[MAX_PID_LIST];
size_t pidLength = 0;

void handler(int sig)
{
    int oldErrno = errno;
    sigset_t maskAll, prevAll;
}

void addJob(pid_t pid)
{
    if (pidLength >= MAX_PID_LIST)
    {
        return;
    }

    pidList[pidLength++] = pid;
}

void deleteJob(pid_t pid)
{
    if (pidLength <= 0)
    {
        return;
    }

    size_t index = MAX_PID_LIST;

    for (size_t i = 0; i < MAX_PID_LIST; ++i)
    {
        if (pidList[i] == pid)
        {
            index = i;

            break;
        }
    }

    if (index != MAX_PID_LIST)
    {
        for (size_t i = 0; i < pidLength - 1; ++i)
        {
            pidList[i] = pidList[i + 1];
        }

        pidLength--;
    }
    else
    {
        Sio_puts("No pid!");
    }
}

int main(int argc, char **argv)
{
    pid_t pid;
    sigset_t maskAll, prevAll;

    Sigfillset(&maskAll);

    while (pidLength < MAX_PID_LIST)
    {
        if ((pid = Fork()) == 0)
        {
            Execve("/bin/date", argv, NULL);
        }

        Sigprocmask(SIG_BLOCK, &maskAll, &prevAll);
        addJob(pid);
        Sigprocmask(SIG_SETMASK, &prevAll, NULL);
    }

    exit(0);
}
