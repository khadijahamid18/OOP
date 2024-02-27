#include <iostream>
using namespace std;
#define SIZE 3

class Algebra
{
    int arr[SIZE];

public:
    void input()
    {
        for (int i = 0; i < SIZE; i++)
        {
            cout << "Enter the elements of array: " << endl;
            cin >> arr[i];
        }
        cout << endl;
    }

    void print()
    {
        for (int i = 0; i < SIZE; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void printArray(Algebra arr[], int size)
    {
        arr->print();
    }
};

int main()
{
    system("cls");
    Algebra arr[SIZE];

    arr->input();

    arr[0].printArray(arr, SIZE);  // for array assigning arguments we should pass the index

    return 0;
}