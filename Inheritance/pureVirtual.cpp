
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

    virtual ~A() // Always make base class destructor virual, to avoid memmory leaks.
    {
        cout << "A's Destructor." << endl;
    }

    virtual void print() // print() would be overriden in child classe(s).
    {
        cout << "dA = " << dA << endl;
    }

    // pure-virtual function. Class A is Abstract now
    virtual void test() = 0; // test() must be overriden in child classe(s), otherwise they will become abstract too.
};

class B : public A // B inherits all the features of A except Constructors, Destructor, Assignment-operator and V-Table
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

    ~B() // B's destructor is also virtual
    {
        cout << "B's Destructor." << endl;
    }

    void print() // overriden function. print() is also virtual here
    {
        A::print(); // making a call to A(parent) class' print member function
        cout << "dB = " << dB << endl;
    }

    void test() // overriden function. test() is also virtual here
    {
        cout << "Class B's Test" << endl;
    }
};

class C : public A // C inherits all the features of A except Constructors, Destructor, Assignment-operator and V-Table
{
    int dC;

public:
    C()
    {
        dC = 0;
        cout << "C's Default Constructor." << endl;
    }

    C(int dA, int dC) : A(dA) // calling A's parameterized constructor
    {
        this->dC = dC;
        cout << "C's Parameterized Constructor." << endl;
    }

    C(const C &obj) : A(obj) // calling A's copy constructor. The object of child class can be assigned to its parent.
    {
        dC = obj.dC;
        cout << "C's Copy Constructor." << endl;
    }

    ~C() // C's destructor is also virtual
    {
        cout << "C's Destructor." << endl;
    }

    void print() // overriden function. print() is also virtual here
    {
        A::print(); // making a call to A(parent) class' print member function
        cout << "dC = " << dC << endl;
    }

    void test() // overriden function. test() is also virtual here
    {
        cout << "Class C's Test" << endl;
    }
};

int main()
{
    // A oa(1);		object of Abstract class can not be instantiated.

    B ob(2, 3);
    C oc(4, 5);

    // pointer of Abstract class can be created.
    A *pa[2] = {&ob, &oc}; // pointer of base-class can hold reference of child class

    for (int i = 0; i < 2; i++)
    {
        pa[i]->test(); // decision will be made on run-time based on object-type, not on pointer's type.
    }

    return 0;
}