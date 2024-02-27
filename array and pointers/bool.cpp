#include <iostream>
using namespace std;

class Algebra
{
    int a;
    int b;

public:

    Algebra(int a1, int b1)
    {
        a = a1;
        b = b1;
    }

    bool equal(const Algebra &obj)
    {
        return (a == obj.a && b == obj.b);
    }

};

int main()
{
    system("cls");

    Algebra o1(2, 7), o2(2, 7);

    cout << o1.equal(o2);


    return 0;
}