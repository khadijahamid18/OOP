#include <iostream>
using namespace std;

class Algebra
{
    int a;
    int b;

public:
    Algebra()
    {
        cout << "Default Constructor" << endl;

        a = b = 0;
    }

    Algebra(int a1, int b1)
    {
        cout << "Parameterized" << endl;
        a = a1;
        b = b1;
    }

    ~Algebra()
    {
        cout << "Destructor..." << endl;
    }

    Algebra sub(const Algebra &obj)
    {
        Algebra temp;
        temp.a = a - obj.a;
        temp.b = b - obj.b;
        return temp;
    }

    void print()
    {
        cout << "a: "<< a << "\t\t" << "b: " << b << endl;
    }
};

int main()
{
    system("cls");
    Algebra o1(8, 9), o2(3, 8), r;
    r = o1.sub(o2);
    r.print();

    return 0;
}
// Firstly o1 ka parameterized constructor call ho ga
// then o2 ka parameterized constructor call ho ga 
// then dono agay jain gy to dono k default constructor call hon gy
// add mn temp ban kr wohi khatm ho jae ga jab a or b bain gy to temp k liye destructor call ho ga
// then a or b ki values print hon gi
// r k liye phr b k liye phr a k liye destructor call ho ga 

// r ka parameterized is liye ni call ho ga bcz uska koi parameter ni 