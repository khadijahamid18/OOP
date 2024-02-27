#include "iostream" 

using namespace std;

class Algebra  
{
public:
    // data members of the class
    int a, b;
    const int c; // constant data member, must be initialized in intializer list of Constructors.

    // declaration of static data member to keep the count of objects
    // static data member has to be defined out side the class
    static int objectCount;

    // static member functions to set the value objectCount static data member.
    static void setObjectCount(int objectCount)
    {
        // this->a = objectCount;	Error, this pointer does not exist in static member function

        Algebra::objectCount = objectCount;
    }

    // static member functions to get the value objectCount static data member.
    static int getObjectCount()
    {
        // return this->a = objectCount;	Error, this pointer does not exist in static member function

        return objectCount;
    }

public:
    // Default Constructor
    Algebra() : c(0)
    {
        cout << "Default Constructor" << endl;

        this->a = this->b = 0;

        objectCount++; // increment the object count
    }

    // Parameterized Constructor
    Algebra(int a, int b, int c) : c(c)
    {
        cout << "Parameterized Constructor" << endl;

        this->a = a;
        this->b = b;

        objectCount++; // increment the object count
    }

    // Copy Constructor
    Algebra(const Algebra &obj) : c(obj.c)
    {
        cout << "Copy Constructor" << endl;

        this->a = obj.a;
        this->b = obj.b;

        objectCount++; // increment the object count
    }

    // Destructor
    ~Algebra()
    {
        cout << "Destructor" << endl;

        objectCount--; // decrement the object count
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
            if ((this->a == ar[i].a) && (this->b == ar[i].b))
                return true;
        }

        return false;
    }
};

// static data members has to be defined outside the class
// static data members are intiliazed with 0 automatically
int Algebra::objectCount;

void testObjects()
{
    Algebra obj1, obj2(1, 2, 3), obj3 = obj2;

    cout << Algebra::getObjectCount() << endl; // access the static data member with its class name
}

int main()
{
    system("cls");

    Algebra obj(4, 5, 6);
    Algebra arr[] = {Algebra(), Algebra(1, 2, 3), Algebra(obj)};

    cout << obj.searchArray(arr, 3) << endl;
    cout << endl << endl;


    cout << Algebra::getObjectCount() << endl; // access the static data member with its class name
    cout << Algebra::objectCount << endl;
    testObjects();
    // obj1.~Algebra();

    // cout << objM.getObjectCount() << endl; // static members can also be accessed with objects.
    // cout << Algebra::objectCount << endl;

    return 0;
}