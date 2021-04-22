/**
 * example06
 * @author Clay
 * @date 2021/4/15
 */

#include <iostream>

int main()
{
    int value = 0, old = 0, count = 0;

    if (std::cin >> old)
    {
        ++count;

        while (std::cin >> value)
        {
            if (value == old)
            {
                ++count;
            }
            else
            {
                std::cout << old << " occurs " << count << " times" << std::endl;

                count = 1;
                old = value;
            }
        }

        std::cout << old << " occurs " << count << " times" << std::endl;
    }
}
