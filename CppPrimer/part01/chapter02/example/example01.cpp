/**
 * example01
 * @author Clay
 * @date 2021/4/19
 */

#include <iostream>

int main()
{
    bool b = 42;
    int i = b;
    i = 3.14;
    double pi = i;
    unsigned char c = -1;
    signed char c2 = 256;

    i = 42;
    if (i)
    {
        i = 0;
    }

    unsigned u = 10;
    i = -42;

    std::cout << i + i << std::endl;
    std::cout << u + i << std::endl;
}
