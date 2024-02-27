#include <iostream>
using namespace std;
#define SIZE 2

class Algebra
{
    int a[SIZE]; 

public:
    void input()
    {
        for (int i = 0; i < SIZE; i++)
        {
            cin >> a[i];
        }
    }

    void print()
    {
        for (int i = 0; i < SIZE; i++)
        {
            cout << a[i] << " ";
        }
    }
};

int main()
{
    system("cls");
    Algebra arr[SIZE];

    cout << "Enter the elements in the array: " << endl;

    arr[SIZE].input();

    arr[SIZE].print();

    // for (int i = 0; i < SIZE; i++)    // // is se loop 2 * size times chal jata bcz double loop ho jata
    // {
    //     arr[i].input();
    // }

    // cout << endl;

    // for (int i = 0; i < SIZE; i++)
    // {
    //     arr[i].print();
    // }

    return 0;
}