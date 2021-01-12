/**
 * ShellEx
 * @author Clay
 * @date 2021/1/11
 */

#include <stdbool.h>
#include "../../../include/csapp.h"

#define MAX_ARGS 128
#define MAX_CHARS 128

void eval(char *cmdline);

bool parseline(char *buffer, char *argv[]);

bool builtinCommand(char *argv[]);

char *getCommand(void);

int main(void)
{
    char *cmdline;

    while (true)
    {
        printf(">");
        cmdline = getCommand();

        if (!cmdline)
        {
            exit(0);
        }

        eval(cmdline);
    }
}

void eval(char *cmdline)
{
    printf("%s\n", cmdline);
}

bool parseline(char *buffer, char *argv[])
{

}

bool builtinCommand(char *argv[])
{

}

char *getCommand()
{
    static int index = 0;

    char *cmdList[MAX_CHARS] =
        {

        };

    char *cmd = cmdList[index++];
    printf("%s\n", cmd);

    return cmd;
}
