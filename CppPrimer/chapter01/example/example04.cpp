/**
 * example04
 * @author Clay
 * @date 2021/4/15
 */

#include <iostream>

int main()
{
    int sum = 0, start = 0, end = 0, i = 0;

    std::cout << "Enter two numbers: " << std::endl;
    std::cin >> start >> end;

    if (start > end)
    {
        int temp = start ^end;

        start = temp ^ start;
        end = temp ^ end;
    }

    i = end;

    while (i >= start)
    {
        sum += i--;
    }

    sum = 0;

    for (i = start; i <= end; ++i)
    {
        sum += i;
    }

    std::cout << "Sum of " << start << " to " << end << " inclusive is " << sum << std::endl;

    return 0;
}
