/**
 * MyLs
 * @author Clay
 * @date 2021/1/28
 */

#include "csapp.h"

int main(int argc, char **argv, char **const envp)
{
    Execve("/bin/ls", argv, envp);

    return 0;
}
