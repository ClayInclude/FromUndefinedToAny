/**
 * example04
 * @author Clay
 * @date 2021/4/21
 */

#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
    string s("some thing");

    for (auto iterator = s.begin(), e = s.end(); iterator != e && !std::isspace(*iterator); ++iterator)
    {
        *iterator = static_cast<char>(toupper(*iterator));
    }

    vector<int> text;

    auto beg = text.begin(), end = text.end(), mid = beg + (end - beg) / 2;

    int sought = 0;

    while (mid != end && *mid != sought)
    {
        if (sought < *mid)
        {
            end = mid;
        }
        else
        {
            beg = mid + 1;
        }

        mid = beg + (end - beg) / 2;
    }

    return 0;
}
