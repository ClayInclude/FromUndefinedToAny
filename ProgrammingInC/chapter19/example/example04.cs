using System;

class Fraction
{
    private int numerator;
    private int denominator;

    public int Numerator
    {
        get
        {
            return numerator;
        }
        set
        {
            numerator = value;
        }
    }

    public int Denominator
    {
        get
        {
            return denominator;
        }
        set
        {
            denominator = value;
        }
    }

    public void print()
    {
        Console.WriteLine("the value of the fraction is {0}/{1}", numerator, denominator);
    }
}

class example
{
    public static void Main()
    {
        Fraction f = new Fraction();

        f.Numerator = 1;
        f.Denominator = 3;
        f.print();
    }
}