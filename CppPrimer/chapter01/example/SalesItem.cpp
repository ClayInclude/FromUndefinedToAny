/**
 * SalesItem
 * @author Clay
 * @date 2021/4/15
 */

#include "SalesItem.h"

std::istream &operator>>(std::istream &in, SalesItem &rhs)
{
    double price;

    in >> rhs.bookNo >> rhs.unitsSold >> price;

    if (in)
    {
        rhs.revenue = rhs.unitsSold * price;
    }
    else
    {
        rhs = SalesItem();
    }

    return in;
}

std::ostream &operator<<(std::ostream &out, SalesItem &rhs)
{
    out << rhs.isbn() << " " << rhs.unitsSold << " " << rhs.revenue << " " << rhs.avgPrice();

    return out;
}

inline bool operator==(const SalesItem &lhs, const SalesItem &rhs)
{
    return lhs.unitsSold == rhs.unitsSold &&
        lhs.revenue == rhs.revenue &&
        lhs.isbn() == rhs.isbn();
}

inline bool operator!=(const SalesItem &lhs, const SalesItem &rhs)
{
    return !(lhs == rhs);
}

SalesItem &operator+(const SalesItem &lhs, const SalesItem &rhs)
{
    auto temp = new SalesItem();

    temp->bookNo = lhs.bookNo;
    temp->unitsSold = lhs.unitsSold + rhs.unitsSold;
    temp->revenue = lhs.revenue + rhs.revenue;

    return *temp;
}

SalesItem::SalesItem(std::string &book)
    : bookNo(std::move(book))
{

}

SalesItem::SalesItem(std::istream &in)
{
    in >> *this;
}

SalesItem &SalesItem::operator+=(const SalesItem &rhs)
{
    unitsSold += rhs.unitsSold;
    revenue += rhs.revenue;

    return *this;
}

inline std::string SalesItem::isbn() const
{
    return bookNo;
}

double SalesItem::avgPrice() const
{
    if (unitsSold)
    {
        return revenue / unitsSold;
    }
    else
    {
        return 0;
    }
}
