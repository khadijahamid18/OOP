#include <iostream>
using namespace std;

class Algebra
{
public:
    int a;
    int b;

    void print()
    {
        cout << a << "\t" << b << endl;
    }
};

int main()
{
    system("cls");
    Algebra obj1, obj2;

    obj1.a = 45;
    obj1.b = 23;

    obj2.a = 13;
    obj2.b = 56;

    obj1.print();
    obj2.print();

    return 0;
}