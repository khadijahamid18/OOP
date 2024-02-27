#include <iostream>
using namespace std;

int main()
{
    system("cls");
    int a = 5;
    int *b = &a;
    int *c = b;

    cout << a << endl;  // 5
    cout << b << endl;  // address of a
    cout << c << endl;  // address of a
    cout << *b << endl; // 5
    cout << *c << endl; // address of a
    cout << &a << endl; // address of a
    cout << &b << endl; // address of b
    cout << &c << endl; // address of c

    return 0;
}