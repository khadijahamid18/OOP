#include <iostream>
using namespace std;

class Algebra
{
public:
    int a;
    int b;
};

int main()
{
    system("cls");
    Algebra obj1, obj2;

    obj1.a = 45;
    obj1.b = 23;

    obj2.a = 13;
    obj2.b = 56;

    cout << obj1.a << "\t" << obj1.b << endl;
    cout << obj2.a << "\t" << obj2.b << endl;

    return 0;
}