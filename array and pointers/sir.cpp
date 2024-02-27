#include "iostream"

using namespace std;

class Algebra
{
    // data members of the class
    int a, b;

public:
    // Default Constructor
    Algebra()
    {
        cout << "Default Constructor" << endl;

        a = b = 0;
    }

    // Parameterized Constructor
    Algebra(int a1, int b1)
    {
        cout << "Parameterized Constructor" << endl;

        setA(a1);
        setB(b1);
    }

    // Copy Constructor
    Algebra(const Algebra &obj)
    {
        cout << "Copy Constructor" << endl;

        a = obj.a;
        b = obj.b;
    }

    // Destructor
    ~Algebra()
    {
        cout << "Desstructor" << endl;
    }

    // setter for data memeber a
    void setA(int a1)
    {
        if (a1 > 0)
            a = a1;
        else
            a = 0;
    }

    // getter for data memeber a
    int getA()
    {
        return a;
    }

    // setter for data memeber b
    void setB(int b1)
    {
        if (b1 > 0)
            b = b1;
        else
            b = 0;
    }

    // getter for data memeber b
    int getB()
    {
        return b;
    }

    // function to set object's data
    void setData(int a1, int b1)
    {
        setA(a1);
        setB(b1);
    }

    // function to take input for object's data
    void input()
    {
        cout << "Enter a = ";
        cin >> a;

        cout << "Enter b = ";
        cin >> b;

        setA(a);
        setB(b);
    }

    // function to display object's data on screen
    void print()
    {
        cout << "a = " << a << "\tb = " << b << endl;
    }

    // function to add two objects (L.H.S and R.H.S) and return their result
    Algebra add(const Algebra &obj)
    {
        Algebra temp;

        temp.a = a + obj.a;
        temp.b = b + obj.b;

        return temp;
    }

    // function to subtract R.H.S object from L.H.S object  and return their result
    Algebra subtract(const Algebra &obj)
    {
        Algebra temp;

        return temp;
    }

    // function to multiply two object (L.H.S and R.H.S) and return their result
    Algebra multiply(const Algebra &obj)
    {
        Algebra temp;

        return temp;
    }

    // function to divide L.H.S object by R.H.S object and return their result
    Algebra divide(const Algebra &obj)
    {
        Algebra temp;

        return temp;
    }

    // function to get the mod of L.H.S object by R.H.S object and return their result
    Algebra mod(const Algebra &obj)
    {
        Algebra temp;

        return temp;
    }

    // function to compare two objects and return the result (true/false)
    bool equal(const Algebra &obj)
    {

        return false;
    }

    /*function to calculate the sum of array objects.
     * The sum should be stored in the L.H.S object(calling object)
     */
    void arraySum(Algebra ar[], const int size)
    {
    }
};

int main()
{
    Algebra obj1(2, 5);
    Algebra obj2(4, 7);
    Algebra r;
    r = obj1.add(obj2);
    r.print();
    cout << endl;
    // intializing array on the creation time
    // Algebra a[] = {Algebra(), Algebra(1, 2), Algebra(3, 4), Algebra(a[1]), Algebra()};

    // Creating array of objects
    Algebra ar[5];

    // setting ar's data
    for (int i = 0; i < 5; i++)
        ar[i].setData(i, i + 1);

    // printing ar's data
    for (int i = 0; i < 5; i++)
        ar[i].print();

    Algebra obj(3, 4);

    //-----------------------------------------------//
    // declaring a pointer of Algebra type
    Algebra *po = &obj;

    // two ways to access members through pointer
    (*po).print(); // first

    po->print(); // second
    //-----------------------------------------------//

    return 0;
}