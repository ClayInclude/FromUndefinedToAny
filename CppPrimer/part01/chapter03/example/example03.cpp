/**
 * example03
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
    vector<int> iVec;
    vector<vector<string>> file;

    using T = int;

    vector<T> v1;
    vector<T> v2(v1);
    vector<T> v3 = v1;
    vector<T> v4(4, 1);
    vector<T> v5(5);
    vector<T> v6{1, 3, 3};

    vector<string> articles = {"a", "an", "the"};

    vector<int> v7(10, 1);
    vector<int> v8{10, 1};

    string word;
    vector<string> text;

    while (cin >> word)
    {
        text.push_back(word);
    }

    return 0;
}
