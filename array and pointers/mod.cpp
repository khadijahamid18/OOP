#include <iostream>
using namespace std;

class Algebra
{
private:
    int a, b;

public:
    Algebra()
    {
        cout << "Default Constructor..." << endl;
        a = b = 0;
    }

    Algebra(float a1, float b1)
    {
        cout << "Parameterized Constructor..." << endl;
        a = a1;
        b = b1;
    }

    ~Algebra()
    {
        cout << "Destructor..." << endl;
    }

    Algebra modulus(const Algebra &obj)
    {
        Algebra temp;
        temp.a = a % obj.a;
        temp.b = b % obj.b;   
        return temp;
    }

    void print()
    {
        cout << "a : " << a << "\t" << "b : " << b << endl;
    }
};

int main()
{
    system("cls");
    Algebra o1(4, 8);
    Algebra o2(6, 2); 
    Algebra r;

    r = o1.modulus(o2);

    r.print();

    return 0;
}