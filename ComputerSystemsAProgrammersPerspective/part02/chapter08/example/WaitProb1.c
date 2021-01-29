/**
 * WaitProb1
 * @author Clay
 * @date 2021/1/11
 */

#include "../../../include/csapp.h"

int main(void)
{
    int status;

    printf("Hello\n");

    pid_t pid = Fork();

    printf("%d\n", !pid);

    if (pid != 0)
    {
        if (waitpid(-1, &status, 0) > 0)
        {
            if (WIFEXITED(status) != 0)
            {
                printf("%d\n", WEXITSTATUS(status));
            }
        }
    }

    printf("Bye\n");

    exit(2);
}
