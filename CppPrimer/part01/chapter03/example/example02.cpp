/**
 * example02
 * @author Clay
 * @date 2021/4/20
 */

#include <iostream>
#include <string>
#include <cctype>

using std::string;
using std::cin;
using std::cout;
using std::endl;

int main()
{
    string s1;
    string s2 = s1;
    string s3 = "hiya";
    string s4(10, 'c');
    string s5(s1);
    string s6 = string(10, 'c');
    string s7{"value"};
    string s8{3, 'c'};
    string s9 = {"value"};

    string s;

    cin >> s;
    cout << s << endl;

    cin >> s1 >> s2;
    cout << s1 << s2 << endl;

    string word;

    while (cin >> word)
    {
        cout << word << endl;
    }

    string line;

    while (std::getline(cin, line))
    {
        if (!line.empty() && line.size() > 80)
        {
            cout << line << endl;
        }
    }

    string::size_type len = line.size();

    s3 = s1 + s2;
    s1 += s2;

    s4 = s1 + ", ";
    s5 = s1 + "hello" + "world";

    for (auto c : s)
    {
        cout << c;
    }

    decltype(s.size()) punctCount = 0;

    for (auto c : s)
    {
        if (std::ispunct(c))
        {
            ++punctCount;
        }
    }

    cout << punctCount << " punctuation characters in " << s << endl;

    for (auto &c : s)
    {
        c = static_cast<char>(std::toupper(c));
    }

    cout << s << endl;

    for (decltype(s.size()) index = 0, length = s.size(); index != length && !std::isspace(s[index]); ++index)
    {
        s[index] = static_cast<char>(std::toupper(s[index]));
    }

    string const hexDigits = "0123456789ABCDEF";

    cout << "Enter a series of number between 0 and 15"
         << " separated by spaces. Hit ENTER whe finished: "
         << endl;

    string result;
    string::size_type n;
    auto hexLen = hexDigits.size();

    while (cin >> n)
    {
        if (n < hexLen)
        {
            result += hexDigits[n];
        }
    }

    cout << "Your hex number is: " << result << endl;

    return 0;
}
