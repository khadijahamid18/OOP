#include <iostream>
using namespace std;

class Algebra
{
public:
    int a;
    int b;

    int add() 
    {
        return a + b;
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

    //cout << obj1.add() << endl;

    int s = obj1.add();
    cout << s;

    
    

    return 0;
}