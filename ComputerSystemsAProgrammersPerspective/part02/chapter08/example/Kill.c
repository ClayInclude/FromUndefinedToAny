/**
 * Kill
 * @author Clay
 * @date 2021/1/14
 */

#include "csapp.h"

int main(void )
{
    pid_t  pid;

    if ((pid = Fork()) == 0)
    {
        Pause();

        printf("control should never reach here!\n");

        exit(0);
    }

    Kill(pid, SIGKILL);

    exit(0);
}
