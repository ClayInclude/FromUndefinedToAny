/**
 * example03
 * @author Clay
 * @date 2021/2/20
 */

#include "csapp.h"

int main(void)
{
    int fd;
    char c;

    fd = Open("foobar.txt", O_RDONLY, 0);

    if (Fork() == 0)
    {
        Read(fd, &c, 1);

        return 0;
    }

    Wait(NULL);

    Read(fd, &c, 1);
    printf("c = %c\n", c);

    return 0;
}
