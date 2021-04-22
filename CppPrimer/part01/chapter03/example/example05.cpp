/**
 * example05
 * @author Clay
 * @date 2021/4/22
 */

#include <iostream>
#include <string>
#include <iterator>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    constexpr unsigned int sz = 42;

    int arr[10];
    int *pArr[sz];
    string strings[sz];

    unsigned int const csz = 3;

    int a1[csz] = {0, 1, 2};
    int a2[csz]{0, 1, 2};

    auto ia(a1);

    int *beg = std::begin(a1);
    int *end = std::end(a1);
}
