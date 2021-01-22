/**
 * ProcMask1
 * @author Clay
 * @date 2021/1/18
 */

#include "csapp.h"

#define MAX_PID_LIST 10

pid_t pidList[MAX_PID_LIST];
size_t pidLength = 0;

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

    size_t index = MAX_PID_LIST + 100;

    for (size_t i = 0; i < MAX_PID_LIST; ++i)
    {
        if (pidList[i] == pid)
        {
            index = i;

            break;
        }
    }

    if (index != MAX_PID_LIST + 100)
    {
        for (size_t i = index; i < pidLength - 1; ++i)
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

void handler(int sig)
{
    int oldErrno = errno;
    sigset_t maskAll, prevAll;
    pid_t pid;

    Sigfillset(&maskAll);

    while ((pid = waitpid(-1, NULL, 0)) > 0)
    {
        Sigprocmask(SIG_BLOCK, &maskAll, &prevAll);
        deleteJob(pid);
        Sigprocmask(SIG_SETMASK, &prevAll, NULL);
    }

    if (errno != ECHILD)
    {
        Sio_error("wait pid error");
    }

    errno = oldErrno;
}

int main(int argc, char **argv)
{
    pid_t pid;
    sigset_t maskAll, prevAll;

    Sigfillset(&maskAll);
    Signal(SIGCHLD, handler);

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
