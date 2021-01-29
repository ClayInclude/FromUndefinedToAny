/**
 * WaitPid3
 * @author Clay
 * @date 2021/1/29
 */

#include "csapp.h"

#define N 4

int main(void)
{
    int status;
    pid_t pid;

    for (int i = 0; i < N; ++i)
    {
        if ((pid = Fork()) == 0)
        {
            exit(100 + i);
        }
    }

    while ((pid = waitpid(-1, &status, 0)) > 0)
    {
        if (WIFEXITED(status))
        {
            printf("child %d terminated normally with exit status=%d\n", pid, WEXITSTATUS(status));
        }
        else if(WIFSIGNALED(status))
        {
            char buf[128];

            sprintf(buf, "child %d terminated by signal %d\n", pid, WTERMSIG(status));
            psignal(WTERMSIG(status), buf);
        }
        else
        {
            printf("child %d terminated abnormally\n", pid);
        }
    }

    if (errno != ECHILD)
    {
        unix_error("waitpid error");
    }

    exit(2);
}

