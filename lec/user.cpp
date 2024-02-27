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
    void input()
    {
        cout << "Enter the value of a: " << endl;
        cin >> a;

        cout << "Enter the value of b: " << endl;
        cin >> b;
    }
};

int main()
{
    system("cls");
    Algebra obj1, obj2;

    obj1.input();
    obj2.input();

    cout << endl;

    obj1.print();
    obj2.print();

    return 0;
}