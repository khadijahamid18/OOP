#include <iostream>
using namespace std;

class RationalNumber
{
private:
    int numerator;
    int denominator;

public:
    // Mutators and Accessors
    void setnumerator(int numerator)
    {
        this->numerator = numerator;
    }
    int getnumerator()
    {
        return this->numerator;
    }

    void setDenominator(int denominator)
    {
        if (denominator > 0)
        {
            this->denominator = denominator;
        }
        else if (denominator == 0)
        {
            denominator = 1;
        }
        else
        {
            this->denominator = -1 * (denominator);
            this->numerator = -1 * (numerator);
        }
    }

    int getDenominator()
    {
        return this->denominator;
    }

    // Constructors

    RationalNumber(int n, int d)
    {
        cout << "Parameterized Constructor..." << endl;
        setnumerator(n);
        setDenominator(d);
    }

    RationalNumber(int n)
    {
        setnumerator(n);
        denominator = 1;
    }

    // Operator Overloading

    RationalNumber operator+(const RationalNumber &obj) const
    {
        RationalNumber result(1, 2);
        result.numerator = numerator * obj.denominator + obj.numerator * denominator;
        result.denominator = denominator * obj.denominator;
        return result;
    }

    RationalNumber operator-(const RationalNumber &obj) const
    {
        RationalNumber result(1, 2);
        result.numerator = numerator * obj.denominator - obj.numerator * denominator;
        result.denominator = denominator * obj.denominator;
        return result;
    }

    RationalNumber operator*(const RationalNumber &obj) const
    {
        return RationalNumber(numerator * obj.numerator, denominator * obj.denominator);
    }

    RationalNumber operator/(const RationalNumber &obj) const
    {
        return RationalNumber(numerator * obj.denominator, denominator * obj.numerator);
    }

    bool operator<(const RationalNumber &obj) const
    {
        return numerator * obj.denominator < obj.numerator * denominator;
    }

    bool operator==(const RationalNumber &obj) const
    {
        if (numerator == obj.numerator && denominator == obj.denominator)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    RationalNumber operator-() const
    {
        return RationalNumber(-numerator, denominator);
    }

    bool operator!() const
    {
        return (numerator < 0);
    }

    friend ostream &operator<<(ostream &out, const RationalNumber &obj);

    friend istream &operator>>(istream &in, RationalNumber &obj);
};

ostream &operator<<(ostream &out, const RationalNumber &obj)
{
    out << obj.numerator << "/" << obj.denominator;
    return out;
}

istream &operator>>(istream &in, RationalNumber &obj)
{
    cout << "Enter the numerator: ";
    in >> obj.numerator;

    cout << "Enter the denominator: ";
    in >> obj.denominator;

    return in;
}

int main()
{
    system("cls");

    RationalNumber r1(2, -3);
    RationalNumber r2(4, 5);

    RationalNumber r3 = r1 + r2;
    RationalNumber r4 = r1 - r2;
    RationalNumber r5 = r1 * r2;
    RationalNumber r6 = r1 / r2;

    cout << "r1 = " << r1 << endl;

    cout << "r2 = " << r2 << endl;

    cout << "ADDITION" << endl;
    cout << "r3 = " << r3 << endl;

    cout << "SUBTRACTION" << endl;
    cout << "r4 = " << r4 << endl;

    cout << "MULTIPLICATION" << endl;
    cout << "r5 = " << r5 << endl;

    cout << "DIVISION" << endl;
    cout << "r6 = " << r6 << endl;

    cout << "Minus unary operator" << endl;
    r2 = -r1;
    cout << r2 << endl;
    cout << endl;

    cout << "Equal binary operator" << endl;
    if (r1 == r2)
        cout << "Rational Numbers are same." << endl;
    else
        cout << "Rational Numbers are not same." << endl;
    cout << endl;

    cout << "Less than binary operator" << endl;
    if (r1 < r2)
        cout << "r1 is less than r2." << endl;
    else
        cout << "r1 is greater than r2." << endl;
    cout << endl;

    cout << "Null Operator!!!!!!" << endl;
    cout << "!r1=" << !r1;

    return 0;
}   