/**
 * WaitPid2
 * @author Clay
 * @date 2021/1/7
 */

#include "../../../include/csapp.h"

#define N 4

int main(void)
{
    int status;
    pid_t pid[N];

    for (int i = 0; i < N; ++i)
    {
        if ((pid[i] = Fork()) == 0)
        {
            exit(100 + i);
        }
    }

    int i = N;
    while ((waitpid(pid[--i], &status, 0)) > 0)
    {
        if (WIFEXITED(status))
        {
            printf("child %d terminated normally with exit status=%d\n", pid[i], WEXITSTATUS(status));
        }
        else
        {
            printf("child %d terminated abnormally\n", pid[i]);
        }
    }

    if (errno != ECHILD)
    {
        unix_error("waitpid error");
    }

    exit(0);
}
