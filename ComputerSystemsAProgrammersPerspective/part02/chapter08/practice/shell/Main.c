/**
 * Main
 * @author Clay
 * @date 2021/1/29
 */

#include "csapp.h"
#include "Shell.h"

char *getCommand(void);

int main(void)
{
    char *cmdline;

    while (true)
    {
        printf("\033[32m%s\033[0m:$ ", getenv("USER"));
        cmdline = getCommand();

        if (!cmdline)
        {
            exit(0);
        }

        eval(cmdline);
    }
}

char cmdList[][MAX_CHARS] =
    {
        "/bin/ls &",
        "dir &",
        "",
        "jobs",
        "&",
        "error test",
        "/bin/echo a 1 2 3 4 5 6 7",
        "quit"
    };

char *getCommand()
{
    static int index = 0;

    char *cmd = cmdList[index++];

    if (cmd)
    {
        printf("\033[32m%s\033[0m\n", cmd);
    }

    return cmd;
}
