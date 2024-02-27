#include <iostream>
using namespace std;

class Algebra
{
public:
    int a;
    int b;
    float t;
};

int main()
{
    system("cls");
    Algebra obj1, obj2, obj3;

    cout << sizeof(obj1) << endl;
    cout << sizeof(obj2) << endl;
    // cout << sizeof(obj3) << endl;
    cout << sizeof(Algebra) << endl;

    return 0;
}