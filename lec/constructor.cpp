#include <iostream>
using namespace std;

class Algebra
{
    int a, b;

public:
    Algebra()
    {
        a = 0;
        b = 0;
        cout << "Default Constructor" << endl;
    }

    Algebra(int a1, int b1)
    {
        a = a1;
        b = b1;
        cout << "Parameterized / Overloaded  Constructor" << endl;
    }

    void print()
    {
        cout << a << "\t" << b << endl;
    }
};

int main()
{
    system("cls");
    Algebra obj1(5, 9);
    Algebra obj2(obj1);  // obj2 = obj1

    obj1.print();
    obj2.print();

    return 0;
}