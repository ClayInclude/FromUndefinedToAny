/**
 * example02
 * @author Clay
 * @date 2021/2/20
 */

#include "csapp.h"

int main(void)
{
    int fd1, fd2;
    char c;

    fd1 = Open("foobar.txt", O_RDONLY, 0);
    fd2 = Open("foobar.txt", O_RDONLY, 0);

    Read(fd1, &c, 1);
    Read(fd2, &c, 1);

    printf("c = %c\n", c);

    return 0;
}
