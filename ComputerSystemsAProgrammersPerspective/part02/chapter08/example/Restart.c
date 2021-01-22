/**
 * Restart
 * @author Clay
 * @date 2021/1/22
 */

#include "csapp.h"

sigjmp_buf buf;

void handler(int sig)
{
    siglongjmp(buf, 1);
}

int main(void)
{
    if (!sigsetjmp(buf, 1))
    {
        Signal(SIGINT, handler);
        Sio_puts("starting\n");
    }
    else
    {
        Sio_puts("restarting\n");
    }

    while (1)
    {
        Sio_puts("processing\n");
        Sleep(1);
    }

    exit(0);
}
