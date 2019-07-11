/**
 * example03
 * @author Clay
 * @version V 1.0.0
 */

#include <iostream>

class Fraction
{
private:
    int numerator = 0;
    int denominator = 0;

public:
    Fraction();
    Fraction(int n, int d);
    void setNumerator(int num);
    void setDenominator(int denom);
    int Numerator();
    int Denominator();
    void print();
};

Fraction::Fraction()
{
    numerator = 0;
    denominator = 0;
}

Fraction::Fraction(int n, int d = 0)
{
    setNumerator(n);
    setDenominator(d);
}

void Fraction::setNumerator(int num)
{
    numerator = num;
}

void Fraction::setDenominator(int denom)
{
    denominator = denom;
}

int Fraction::Numerator()
{
    return numerator;
}

int Fraction::Denominator()
{
    return denominator;
}

void Fraction::print()
{
    std::cout << "The value of the fraction is " << Numerator() << "/" << Denominator() << std::endl;
}

int main()
{
    Fraction f(1, 3);

    f.print();
}
