/**
 * SalesItem
 * @author Clay
 * @date 2021/4/15
 */

#ifndef CPP_PRIMER_C_01_E_SALES_ITEM_H
#define CPP_PRIMER_C_01_E_SALES_ITEM_H

#include <iostream>
#include <string>

class SalesItem
{
    friend std::istream &operator>>(std::istream &in, SalesItem &rhs);

    friend std::ostream &operator<<(std::ostream &out, SalesItem &rhs);

    friend bool operator==(const SalesItem &lhs, const SalesItem &rhs);

    friend bool operator!=(const SalesItem &lhs, const SalesItem &rhs);

    friend SalesItem &operator+(const SalesItem &lhs, const SalesItem &rhs);

public:
    SalesItem() = default;

    SalesItem(std::string &book);

    SalesItem(std::istream &in);

public:
    SalesItem &operator+=(const SalesItem &rhs);

    std::string isbn() const;

    double avgPrice() const;

private:
    std::string bookNo;

    unsigned unitsSold = 0;

    double revenue = 0.0;
};

inline bool compareIsbn(const SalesItem &lhs, const SalesItem &rhs)
{
    return lhs.isbn() == rhs.isbn();
}

#endif // CPP_PRIMER_C_01_E_SALES_ITEM_H
