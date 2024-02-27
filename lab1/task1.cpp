#include <iostream>
using namespace std;
#define SIZE 10
int *pairWiseSum(const int ar[], const int size, int &newArraySize)
{
    int newSize = (size / 2) + 1;

    if (ar == NULL)
    {
        return NULL;
    }

    int *arrNew = new int[newSize];

    for (int i = 0; i < size; i = i + 2)
    {
        if (size % 2 != 0)
        {
            if (i == size - 1)
            {
                arrNew[newArraySize] = ar[size - 1];
                newArraySize++;
                break;
            }
        }
        arrNew[newArraySize] = ar[i] + ar[i + 1];
        newArraySize++;
    }
    return arrNew;
}

int main()
{
    system("cls");
    int size = 0;

    cout << "Enter size of array: ";
    cin >> size;

    int *arr = new int[size];
    int *newArr;
    int sizeNew = 0;

    cout << "Please enter content: \n";
    for (int i = 0; i < size; i++)
    {
        cout << "Enter number: ";
        cin >> arr[i];
    }

    newArr = pairWiseSum(arr, size, sizeNew);

    cout << "Pair wise sum of array: " << endl;
    for (int i = 0; i < sizeNew; i++)
    {
        cout << newArr[i] << "\t";
    }
    delete[] arr;
    delete[] newArr;

    return 0;
}