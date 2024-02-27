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

    int sum()
    {
        int sum = 0;
        for (int i = 0; i < SIZE; i++)
        {
            sum += arr[i];
        }
        return sum;
    }

};

int main()
{
    system("cls");
    Algebra arr1[SIZE];
    arr1->input();
    arr1->print();

    cout << endl;

    cout << arr1->sum(); 

    return 0;
}