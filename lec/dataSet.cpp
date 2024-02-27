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
    
    void setData(int a1, int b1)
    {
        a = a1;
        b = b1;
    }
};

int main()
{
    system("cls");
    Algebra obj1, obj2;

    obj1.setData(8, 9);
    //obj2.input();
    obj2.setData(5, 2);

    obj1.print();
    obj2.print();
    

    return 0;
}