/**
 * HelloWorld
 * @author Clay
 * @date 2020/12/24
 */

#include <io.h>
#include <unistd.h>

int main(void)
{
    write(1, "hello, world\n", 13);

    _exit(0);
}
