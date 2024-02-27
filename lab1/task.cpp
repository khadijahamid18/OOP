#include <iostream>
using namespace std;
#define SIZE 10
int* pairWiseSum(const int ar[], const int size, int& newArraySize)
{
    
}

int main()
{
    system("cls");
    int arr[SIZE];
    int res[SIZE / 2];
    for (int i = 0; i < SIZE; i++)
    {
        cout << "Enter any number: " << endl;
        cin >> arr[i];
    }
    cout << endl;
    cout << "Entered array is: " << endl;
    for (int i = 0; i < SIZE; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    int x = SIZE;
    int y = SIZE / 2;

    for (int i = 0; i < y; i++)
    {
        int j = j + 1;
        res[i] = arr[i] + arr[j];
    }

    cout << "Final array is: " << endl;

    for (int i = 0; i < 5; i++)
    {
        cout << res[i] << " ";
    }

    return 0;
}