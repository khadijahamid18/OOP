#include <iostream>
using namespace std;

class Algebra
{
    int a;
    int b;

public:
    Algebra()
    {
        cout << "Default Constructor" << endl;

        a = b = 0;
    }

    Algebra(int a1, int b1)
    {
        cout << "Parameterized" << endl;
        setA(a1);
        setB(b1);
    }

    ~Algebra()
    {
        cout << "Destructor..." << endl;
    }

    void setA(int a1)
    {
        if (a1 > 0)
            a = a1;
        else
            a = 0;
    }

    int getA()
    {
        return a;
    }

    void setB(int b1)
    {
        if (b1 > 0)
            b = b1;
        else
            b = 0;
    }

    int getB()
    {
        return b;
    }

    Algebra multiply(const Algebra &obj)
    {
        Algebra temp;
        temp.a = a * obj.a;
        temp.b = b * obj.b;
        return temp;
    }

    void print()
    {
        cout << "a: "<< a << "\t\t" << "b: " << b << endl;
    }
};

int main()
{
    system("cls");
    Algebra o1(1, 4), o2(3, 8), r;
    r = o1.multiply(o2);
    r.print();

    return 0;
}
