/**
 * example04
 * @author Clay
 * @date 2021/4/19
 */

#include <iostream>

constexpr int getSizeConst()
{
    return 512;
}

int getSize()
{
    return 512;
}

extern const int buffSize = getSize();

int gj = 0;
constexpr int gi = 42;

int main()
{
    int const cBuffSize = 512;

    // buffSize = 512;

    int const ci = getSize();
    int const cj = 42;
    // int const k;

    int i = 42;
    int const cii = i;
    int j = cii;

    int const &cr = ci;

    // cr = 42;
    // int &cr2 = ci;

    int const &r1 = i;
    int const &r2 = 42;
    int const &r3 = r1 * 2;

    // int &r4 = r1 * 2;

    double dVal = 3.14;
    int const &ri = dVal; // int const temp = dVal; int const &ri = temp;

    int &r4 = i;

    std::cout << r1 << std::endl;

    ++i;

    std::cout << r1 << std::endl;

    double const pi = 3.14;
    // double *ptr = &pi;
    double const *cPtr = &pi;

    double dPi = 3.14;
    cPtr = &dPi;

    int errNum = 0;

    int *const curErr = &errNum;

    // curErr = &errNum;

    double const *const pip = &pi;

    return 0;

    int const maxFiles = 20;
    int const limit = maxFiles + 1;
    int staffSize = 27;

    int const sz = getSize();

    constexpr int mf = 20;
    constexpr int l = mf + 1;
    constexpr int s = getSizeConst();

    constexpr int const *cp = &gj;
    constexpr int *pl = &gj;
}
