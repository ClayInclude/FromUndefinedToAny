/**
 * practice02
 * @author Clay
 * @date 2021/4/19
 */

#include <iostream>
#include <string>

std::string globalStr;

int main()
{
    char c = 'a';
    wchar_t c2 = L'a';
    char c3[2] = "a";
    wchar_t c4[2] = L"a";

    int i = 10;
    unsigned int i2 = 10u;
    long int i3 = 10L;
    unsigned long int i4 = 10UL;
    int i5 = 012;
    int i6 = 0XC;

    int input_value;

    std::cin >> input_value;

    int i7(3.14);
    int i8 = 3.14;
    double salary = 9999.99, wage = salary;

    int localInt;
    std::string localStr;

    std::cout << localInt << std::endl;
    std::cout << localStr << std::endl;
    std::cout << globalStr << std::endl;

    return 0;
}
