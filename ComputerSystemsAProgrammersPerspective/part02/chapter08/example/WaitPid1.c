/**
 * WaitPid1
 * @author Clay
 * @date 2020/12/25
 */

#include "../../../include//csapp.h"

#define N 4

int main(void)
{
    int status;
    pid_t pid;

    for (int i = 0; i < N; ++i)
    {
        if ((pid = Fork()) == 0)
        {
            exit(100 + 1);
        }
    }

    while ((pid = Waitpid(-1, &status, 0)) > 0)
    {
        
    }
}
