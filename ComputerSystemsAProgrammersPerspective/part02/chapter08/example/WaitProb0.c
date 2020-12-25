/**
 * WaitProb0
 * @author Clay
 * @date 2020/12/25
 */

#include "../../../include/csapp.h"

int main(void)
{
    if (Fork() == 0)
    {
        printf("a");
        fflush(stdout);
    }
    else
    {
        printf("b");
        fflush(stdout);
        Waitpid(-1, NULL, 0);
    }

    printf("c");
    fflush(stdout);

    return 0;
}
