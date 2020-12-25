/**
 * Fork
 * @author Clay
 * @date 2020/12/25
 */

#include "../../../include/csapp.h"

int main(void)
{
    pid_t pid;
    int x = 1;

    pid = Fork();

    // Child
    if (pid == 0)
    {
        printf("child: x = %d\n", ++x);

        exit(0);
    }

    // Parent
    printf("parent: x = %d\n", --x);

    exit(0);
}
