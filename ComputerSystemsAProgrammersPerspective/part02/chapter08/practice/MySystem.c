/**
 * MySystem
 * @author Clay
 * @date 2021/1/29
 */

#include "csapp.h"

int mySystem(char *command);

int main(void)
{
    int code;

    code = mySystem("./ComputerSystemsAProgrammersPerspective_c08_p_ExitCode");

    printf("normally exit, code: %d\n", code);

    code = mySystem("./ComputerSystemsAProgrammersPerspective_c08_p_WaitSig");

    printf("exit caused by signal, code: %d\n", code);

    return 0;
}

int mySystem(char *command)
{
    pid_t pid;

    if ((pid = Fork()) == 0)
    {
        char *argv[] = {"/bin/sh", "-c", command, NULL};
        Execve("/bin/sh", argv, environ);
    }

    printf("child pid = %d\n", pid);

    int status;

    if (Waitpid(pid, &status, 0) > 0)
    {
        if (WIFEXITED(status))
        {
            return WEXITSTATUS(status);
        }

        if (WIFSIGNALED(status))
        {
            return WTERMSIG(status);
        }
    }

    return -1;
}
