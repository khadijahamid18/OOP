#include <iostream>
using namespace std;

class Box
{
    double length;  // Length of a box
    double breadth; // Breadth of a box
    double height;  // Height of a box
public:
    // Constructor definition
    Box(double l, double b, double h)
    {
        cout << "Constructor called." << endl;
        length = l;
        breadth = b;
        height = h;
    }
    double Volume()
    {
        return length * breadth * height;
    }
};

int main()
{
    Box box1(3.3, 1.2, 1.5); // Declare box1
    Box box2(8.5, 6.0, 2.0); // Declare box2
    // Now try to access a member using member access operator
    cout << "Volume of Box1: " << box1.Volume() << endl;

    // Now try to access a member using member access operator
    cout << "Volume of Box2: " << box2.Volume() << endl; 

    return 0;
}