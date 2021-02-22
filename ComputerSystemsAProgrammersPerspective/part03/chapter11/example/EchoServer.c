/**
 * EchoServer
 * @author Clay
 * @date 2021/2/22
 */

#include <stdbool.h>
#include "csapp.h"

void echo(int connFd);

int main(int argc, char **argv)
{
    int listenFd, connFd;
    socklen_t clientLen;
    struct sockaddr_storage clientAddr;
    char clientHostname[MAXLINE], clientPort[MAXLINE];

    if (argc != 2)
    {
        fprintf(stderr, "usage: %s <port>\n", argv[0]);

        exit(0);
    }

    listenFd = Open_listenfd(argv[1]);

    while (true)
    {
        clientLen = sizeof(struct sockaddr_storage);
        connFd = Accept(listenFd, (SA *)&clientAddr, &clientLen);
        Getnameinfo((SA *) &clientAddr, clientLen, clientHostname, MAXLINE, clientPort, MAXLINE, 0);
        printf("Connected to (%s, %s)\n", clientHostname, clientPort);
        echo(connFd);
        Close(connFd);
    }

    exit(0);
}
