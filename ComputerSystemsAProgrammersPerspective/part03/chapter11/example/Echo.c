/**
 * Echo
 * @author Clay
 * @date 2021/2/22
 */

#include "csapp.h"

void echo(int connFd)
{
    size_t n;
    char buf[MAXLINE];
    rio_t rio;

    Rio_readinitb(&rio, connFd);
    while ((n = Rio_readlineb(&rio, buf, MAXLINE)))
    {
        printf("Server received %d bytes\n", (int) n);
        Rio_writen(connFd, buf, n);
    }
}
