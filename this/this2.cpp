
#include "iostream"

using namespace std;

class Algebra
{
    // data members of the class
    int a, b;
    const int c; // constant data member, must be initialized in intializer list of Constructors.

public:
    // Default Constructor
    Algebra() : c(0)
    {
        cout << "Default Constructor" << endl;

        this->a = this->b = 0;
    }

    // Parameterized Constructor
    Algebra(int a, int b, int c) : c(c)
    {
        cout << "Parameterized Constructor" << endl;

        this->a = a;
        this->b = b;
    }

    // Copy Constructor
    Algebra(const Algebra &obj) : c(obj.c)
    {
        cout << "Copy Constructor" << endl;

        this->a = obj.a;
        this->b = obj.b;
    }

    // Destructor
    ~Algebra()
    {
        cout << "Destructor" << endl;
    }

    // setter for data memeber a
    void setA(int a)
    {
        this->a = a;
    }

    // getter for data memeber a
    int getA() const
    {
        return this->a;
    }

    // setter for data memeber b
    void setB(int b)
    {
        this->b = b;
    }

    // getter for data memeber b
    int getB() const
    {
        return this->b;
    }

    // function to set object's data
    void setData(int a, int b)
    {
        this->a = a;
        this->b = b;
    }

    // function to take input for object's data
    void input()
    {
        cout << "Enter a = ";
        cin >> this->a;

        cout << "Enter b = ";
        cin >> this->b;
    }

    // function to display object's data on screen
    void print() const
    {
        // this->a = 5;	Error, left-hand-side object's reference is constant

        cout << "a = " << this->a << "\tb = " << this->b << "\tc = " << this->c << endl;
    }

    // function to add two objects and return their result
    Algebra add(const Algebra &obj) const
    {
        // this->a = 5;	Error, left-hand-side object's reference is constant

        Algebra temp;

        temp.a = this->a + obj.a;
        temp.b = this->b + obj.b;

        return temp;
    }

    // search the left hand side object in the array passed as argument
    bool searchArray(const Algebra ar[], int size) const
    {
        for (int i = 0; i < size; i++)
        {
            if ((a == ar[i].a) && (b == ar[i].b))
                return true;
        }

        return false;
    }
};

int main()
{
    Algebra obj(1, 2, 3);
    obj.print();

    // declaring constant object
    const Algebra objc(4, 5, 6);

    // objc.input();	Error, reference of constant object cannot be passed to non-constant member function.

    objc.print(); // 4	5 6

    return 0;
}