#include "iostream"

using namespace std;

class Algebra
{
    // data members of the class
    int a, b;
    const int c;

public:
    // Default Constructor
    Algebra() : c(0)
    {
        a = b = 0;

        // cout << "Default Constructor" << endl;
    }

    // Parameterized Constructor
    Algebra(int a, int b, int c) : c(c)
    {
        this->a = a;
        this->b = b;

        // setA(a1);
        // setB(b1);

        // cout << "Parameterized Constructor" << endl;
    }

    // Copy Constructor
    Algebra(const Algebra &obj) : c(obj.c)
    {
        this->a = obj.a;
        this->b = obj.b;

        // cout << "Copy Constructor" << endl;
    }

    // Destructor
    ~Algebra()
    {
        // cout << "Destructor" << endl;
    }

    // setter for data memeber a
    void setA(int a1)
    {
        if (a1 < 0)
            a = 0;
        else
            a = a1;
    }

    // getter for data memeber a
    int getA() const
    {
        return a;
    }

    // setter for data memeber b
    void setB(int b1)
    {
        if (b1 < 0)
            b = 0;
        else
            b = b1;
    }

    // getter for data memeber a
    int getB() const
    {
        return b;
    }

    // getter for data memeber c
    int getC() const
    {
        return c;
    }

    // function to set object's data
    void setData(int a1, int b1)
    {
        setA(a1);
        setB(b1);
    }

    // function to take input for object's data
    void getData()
    {
        cout << "Enter a = ";
        cin >> a;
        this->setA(a);

        cout << "Enter b = ";
        cin >> b;
        setB(b);
    }

    // function to display object's data on screen
    void putData() const
    {
        cout << "a = " << this->a;
        cout << "\tb = " << this->b;
        cout << "\tc = " << this->c << endl;
    }

    // overloaded + binary operator
    Algebra operator+(const Algebra &obj) const
    {
        return Algebra(a + obj.a, b + obj.b, c + obj.c);
    }

    // overloaded - binary operator
    Algebra operator-(const Algebra &obj) const
    {
        return Algebra(a - obj.a, b - obj.b, c - obj.c);
    }

    // overloaded assignment operator
    Algebra operator=(const Algebra &obj)
    {
        if (this != &obj) // avoiding self-assignment
        {
            this->a = obj.a;
            this->b = obj.b;

            // this->c = obj.c;		Error: constant data member
        }

        return *this;
    }

    // overloaded binary += operator
    Algebra operator+=(const Algebra &obj)
    {
        this->a += obj.a;
        this->b += obj.b;

        // this->c = obj.c;		Error: constant data member

        return *this;
    }

    // overloaded == operator
    bool operator==(const Algebra &obj) const
    {
        return ((a == obj.a) && (b == obj.b) && (c == obj.c));
    }

    // overloaded != operator
    bool operator!=(const Algebra &obj) const
    {
        return !(*this == obj);
    }

    // overloaded - operator (unary)
    Algebra operator-() const
    {
        return Algebra(-a, -b, -c);
    }

    // overloaded pre-increment ++ operator (unary)
    Algebra operator++()
    {
        ++a;
        ++b;

        return *this;
    }

    // overloaded post-increment ++ operator (unary)
    Algebra operator++(int)
    {
        Algebra oldState(*this);

        ++a;
        ++b;

        return oldState;
    }

    // making stream-insertion global operator a friend of Algebra
    friend ostream &operator<<(ostream &, const Algebra &);

    // making stream-extraction global operator a friend of Algebra
    friend istream &operator>>(istream &, Algebra &);
};

// overloaded stream-insertion << operator
ostream &operator<<(ostream &out, const Algebra &obj)
{
    out << "a = " << obj.a << "\tb = " << obj.b << "\tc = " << obj.c << endl;

    return out;
}

// overloaded stream-extraction << operator
istream &operator>>(istream &in, Algebra &obj)
{
    cout << "Enter a = ";
    in >> obj.a;

    cout << "Enter b = ";
    in >> obj.b;

    return in;
}

int main()
{
    system("cls");
    Algebra obj1(1, 2, 3), obj2(4, 5, 6), obj3(7, 8, 9);

    Algebra r1 = ++obj1; // Algebra r1 = obj1.operator();

    cout << r1 << obj1 << endl; // operator(cout, r1);

    Algebra r2 = obj2++; // Algebra r1 = obj1.operator(0);

    cout << r2 << obj2 << endl; // operator(cout, r2);

    cin >> obj3;  // operator(cin, obj3);
    cout << obj3; // operator(cout, obj3)

    return 0;
}