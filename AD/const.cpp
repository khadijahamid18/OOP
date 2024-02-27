#include <iostream>
using namespace std;

class Player
{
    int x, y;

public:
    Player()
    {
        x = 0;
        y = 0;
    }

    Player(int xx, int yy)
    {
        cout << "Parametric Constructor!" << endl;
        x = xx;
        y = yy;
    }

    void setx(int xx)
    {
        x = xx;
    }

    int getX() const
    {
        return x;
    }

    void setY(int yy)
    {
        y = yy;
    }

    int getY() const
    {
        return y;
    }

    ~Player()
    {
        cout << x << " "
             << "Destroyed!" << endl;
    }

    Player(const Player &obj)
    {
        cout << "Copy Constructor!" << endl;
        x = obj.x;
        y = obj.y;
    }
    void init()
    {
        x = 0;
        y = 0;
    }

    void print() const
    {
        cout << x << " " << y << endl;
    }
};

void print(const Player &obj)
{
    obj.print();
    // cout << obj.getX() << " " << obj.getY() << endl;
}

int main()
{

    const Player p1(2, 3), p2(p1);
    // p1 = p2;   // No Copy Constructor bcz p1 and p2 are already made
    // p1.init();
    // p1.print();
    // p1.~Player();
    // p1.print();
    // p1.setx(10);
    // p1.print();
    // print(p1);  // global function
    //  p1.print();
    // p1.print(&p1);  // matlb k andar kuch ni hota to to LHS ka reference hi hota hy jo this catch krta hy

    // Player* ptr1 = &p1;

    int x = 10;
    int *ptr = &x;
    cout << x << endl;
    cout << &x << endl;
    cout << ptr << endl;  // ptr mn x ka address hy (ptr = *x)
    cout << *ptr << endl; // *ptr mn x ki value hy means dereferencing (*ptr = x)
    cout << &ptr << endl; // &ptr mn ptr ka apna address hy

    // x = 20;
    // *ptr = 20;

    return 0;
}
