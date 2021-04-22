/**
 * sales
 * @author Clay
 * @date 2021/4/15
 */

#include "SalesItem.h"

int main()
{
    SalesItem old;

    if (std::cin >> old)
    {
        SalesItem cur;

        while (std::cin >> cur)
        {
            if (cur.isbn() == old.isbn())
            {
                old += cur;
            }
            else
            {
                std::cout << old << std::endl;

                old = cur;
            }
        }

        std::cout << old;
    }
    else
    {
        std::cerr << "No data?:" << std::endl;

        return -1;
    }

    return 0;
}
