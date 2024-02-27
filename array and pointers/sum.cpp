#include <iostream>

using namespace std;

// create a class
class Array
{
    // private data member
private:
    int array[5];

    // public functions
public:
    // putArray() function to get the value of the array
    void putArray()
    {
        for (int i = 0; i <= 4; i++) 
        {
            cout << "array[" << i << "]:  ";
            cin >> array[i];
        }
    }

    // add() function to find the sum of all numbers of the array
    int add()
    {
        int sum = 0;

        // for loop to add all elements of the array one by one
        for (int i = 0; i <= 4; i++)
        {
            sum = sum + array[i];
        }

        // returning the Sum
        return sum;
    }
};

int main()
{
    // create an object
    Array A;

    // int type variable to store the Sum of all numbers in it
    int sum;

    // function is called by the object to store the array
    A.putArray();

    // add() function to add all elements of the array
    sum = A.add();

    cout << "Sum of all elements of the array is " << sum;

    return 0;
}
