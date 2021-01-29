/**
 * Shell
 * @author Clay
 * @date 2021/1/29
 */

#include "Shell.h"

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
                printf("\033[34m%s\033[0m: \033[31mCommand not found.\033[0m\n", argv[0]);

                exit(0);
            }
        }

        if (inBackground)
        {
            printf("\033[34m%d %s\033[0m\n", pid, cmdline);
        }
        else
        {
            int status;

            if (waitpid(pid, &status, 0) < 0)
            {
                unix_error("\033[31mWait front ground: wait pid error\033[0m");
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
    else if (strcmp(cmd, "jobs") == 0)
    {
        printJob();

        return true;
    }
    else if (strcmp(cmd, "bg") == 0)
    {
        printf("bg not dev");

        return true;
    }
    else if (strcmp(cmd, "fg") == 0)
    {
        printf("fg not dev");

        return true;
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
