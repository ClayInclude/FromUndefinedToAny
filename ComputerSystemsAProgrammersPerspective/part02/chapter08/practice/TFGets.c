/**
 * TFGets
 * @author Clay
 * @date 2021/1/29
 */

#include "csapp.h"

sigjmp_buf buffer;

void handler(int sig)
{
    siglongjmp(buffer, 1);
}

char *tFGets(char *s, int size, FILE* stream)
{
    if (!sigsetjmp(buffer, 1))
    {
        alarm(5);

        Signal(SIGALRM, handler);

        return fgets(s, size, stream);
    }
    else
    {
        return NULL;
    }
}

int main(int argc, char **argv)
{
    char buf[100];
    char *input = tFGets(buf, 100, stdin);

    if (input == NULL)
    {
        printf("nothing input\n");
    }
    else
    {
        printf("%s", input);
    }

    return 0;
}
