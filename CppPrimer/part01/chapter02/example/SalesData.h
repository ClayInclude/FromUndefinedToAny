/**
 * SalesData
 * @author Clay
 * @date 2021/4/20
 */

#ifndef CPP_PRIMER_C_02_E_SALES_DATA_H
#define CPP_PRIMER_C_02_E_SALES_DATA_H

#include <string>

struct SalesData
{
public:
    std::string bookNo;
    unsigned int unitsSold = 0;
    double revenue = 0.0;
};

#endif // CPP_PRIMER_C_02_E_SALES_DATA_H
