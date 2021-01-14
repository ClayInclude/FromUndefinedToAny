/**
 * ShellEx
 * @author Clay
 * @date 2021/1/11
 */

#include <stdbool.h>
#include "csapp.h"

#define MAX_ARGS 128
#define MAX_CHARS 1280

void eval(char *cmdline);

bool parseline(char *buffer, char *argv[]);

bool builtinCommand(char *argv[]);

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

/**
 * 执行
 * @param cmdline
 */
void eval(char *cmdline)
{
    char *argv[MAX_ARGS];
    char buffer[MAX_CHARS];
    bool inBackground;
    pid_t pid;

    inBackground = parseline(strcpy(buffer, cmdline), argv);

    if (argv[0] == NULL)
    {
        return;
    }

    if (!builtinCommand(argv))
    {
        if ((pid = Fork()) == 0)
        {
            // exec 从不返回，除非出错
            if (execve(argv[0], argv, environ) < 0)
            {
                printf("%s: Command not found.\n", argv[0]);

                exit(0);
            }
        }

        if (inBackground)
        {
            printf("%d %s\n", pid, cmdline);
        }
        else
        {
            int status;

            if (waitpid(pid, &status, 0) < 0)
            {
                unix_error("wait front ground: wait pid error");
            }
        }
    }
}

/**
 * 解析命令行参数，返回是否为后台执行
 * @param buffer
 * @param argv
 * @return
 */
bool parseline(char *buffer, char *argv[])
{
    char *cursor;
    int argc = 0;
    bool inBackground;

    size_t len = strlen(buffer);

    if (buffer[len - 2] == '\r')
    {
        buffer[len - 2] = buffer[len - 1] = ' ';
    }
    else if (buffer[len - 1] == '\n')
    {
        buffer[len - 1] = ' ';
    }
    else
    {
        buffer[len] = ' ';
    }

    while (*buffer && (*buffer == ' '))
    {
        ++buffer;
    }

    while ((cursor = strchr(buffer, ' ')))
    {
        argv[argc++] = buffer;
        *cursor = '\0';
        buffer = cursor + 1;

        while (*buffer && (*buffer == ' '))
        {
            ++buffer;
        }
    }

    argv[argc] = NULL;

    if (argc == 0)
    {
        return true;
    }

    if ((inBackground = (*argv[argc - 1] == '&')))
    {
        argv[argc - 1] = NULL;
    }

    return inBackground;
}

/**
 * 如果是内置命令，执行并返回 true
 * @param argv
 * @return
 */
bool builtinCommand(char *argv[])
{
    char const *cmd = argv[0];

    if (strcmp(cmd, "quit") == 0)
    {
        exit(0);
    }
    else if (strcmp(cmd, "&") == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

char cmdList[][MAX_CHARS] =
    {
        "ls -l &",
        "dir &",
        "",
        "&",
        "error test",
        "echo a 1 2 3 4 5 6 7",
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
