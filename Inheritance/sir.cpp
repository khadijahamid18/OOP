#include "iostream"

using namespace std;

class A
{
    int dA;

public:
    A()
    {
        dA = 0;
        cout << "A's Default Constructor." << endl;
    }

    A(int dA)
    {
        this->dA = dA;
        cout << "A's Parameterized Constructor." << endl;
    }

    A(const A &obj)
    {
        dA = obj.dA;
        cout << "A's Copy Constructor." << endl;
    }

    ~A()
    {
        cout << "A's Destructor." << endl;
    }

    void print()
    {
        cout << "dA = " << dA << endl;
    }
};

class B : public A // B inherits all the features of A except Constructors, Destructor and Assignment-operator
{
    int dB;

public:
    B()
    {
        dB = 0;
        cout << "B's Default Constructor." << endl;
    }

    B(int dA, int dB) : A(dA) // calling A's parameterized constructor
    {
        this->dB = dB;
        cout << "B's Parameterized Constructor." << endl;
    }

    B(const B &obj) : A(obj) // calling A's copy constructor. The object of child class can be assigned to its parent.
    {
        dB = obj.dB;
        cout << "B's Copy Constructor." << endl;
    }

    ~B()
    {
        cout << "B's Destructor." << endl;
    }

    void print()
    {
        A::print(); // making a call to A(parent) class' print member function
        cout << "dB = " << dB << endl;
    }
};

class C : public B
{
    int dC;

public:
    C()
    {
        dC = 0;
        cout << "C's Default Constructor." << endl;
    }

    C(int dA, int dB, int dC) : B(dA, dB) // calling B's parameterized constructor
    {
        this->dC = dC;
        cout << "C's Parameterized Constructor." << endl;
    }

    C(const C &obj) : B(obj) // calling A's copy constructor. The object of child class can be assigned to its parent.
    {
        dC = obj.dC;
        cout << "C's Copy Constructor." << endl;
    }

    ~C()
    {
        cout << "C's Destructor." << endl;
    }

    void print()
    {
        B::print(); // making a call to A(parent) class' print member function
        cout << "dC = " << dC << endl;
    }
};

int main()
{
    A oa(5);
    B ob(1, 2);

    oa.print();

    ob.A::print(); // making a call to A(parent) class' print member function
    ob.print();    // making a call to B(child) class' print member function

    oa = ob;    // The object of child class can be assigned to its parent. Because every object of B(child) class is-a object of A(parent) class.
    oa.print(); // A(parent) class' print member function will be called, because the call will be made on the basis of object type not on memory's type.

    return 0;
}