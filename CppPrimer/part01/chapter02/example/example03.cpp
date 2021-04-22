/**
 * example03
 * @author Clay
 * @date 2021/4/19
 */

#include <cstdlib>
#include <iostream>

int main()
{
    int iVal = 1024;
    int &refVal = iVal;
    // int &refVal2;

    refVal = 2;

    int ii = refVal;
    int &refVal3 = refVal;
    int i = refVal;

    int *ip1, *ip2;
    double dp, *dp2;

    int *p = &iVal;

    int *p1 = nullptr;
    int *p2 = 0;
    int *p3 = NULL;

    int *pi = 0;
    int *pi2 = &i;
    int *pi3;

    pi3 = pi2;
    pi2 = 0;

    double obj = 3.14, *pd = &obj;

    void *pv = &obj;
    pv = pd;

    int **ppi = &pi;

    std::cout << "The value of iVal" << std::endl
              << "direct value: " << iVal << " " << std::endl
              << "indirect value: " << *pi << " " << std::endl
              << "doubly indirect value: " << **ppi << " " << std::endl;

    int *&rp = p;

    rp = &i;
    *rp = 0;
}
