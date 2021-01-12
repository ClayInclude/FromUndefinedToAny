/**
 * Echo
 * @author Clay
 * @date 2021/1/11
 */

#include "../../../include/csapp.h"

int main(int argc, char *argv[], char *envp[])
{
    size_t i = 0;

    printf("Commandline arguments:\n");

    while (argv[i])
    {
        printf("    argv[%3zu]: %s\n", i, argv[i]);

        ++i;
    }

    printf("Environment variables:\n");

    i = 0;
    while (envp[i])
    {
        printf("    envp[%3zu]: %s\n", i, envp[i]);

        ++i;
    }

    return 0;
}
