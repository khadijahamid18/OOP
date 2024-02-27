#include <iostream>
#include <string>

using namespace std;
#define SIZE 100

char *reverseCase(const char *str)
{
    cout << str << endl;
    int size = 0;

    while (str[size] != NULL)
    {
        size++;
    }
    
    char *strNew = new char[size];
    int count = 0;

    for (int i = 0; i < size; i++)
    {
        if (str[i] <= 'Z' && str[i] >= 'A')
        {
            strNew[count] = str[i] + 32;
        }
        else if (str[i] <= 'z' && str[i] >= 'a')
        {
            strNew[count] = str[i] - 32;
        }
        else
        {
            strNew[count] = str[i];
        }
        count++;
        if (i == 0)
        {
            strNew[count] = NULL;
        }
    }
    return strNew;
}
int main()
{
    system("cls");
    char str[SIZE];
    char *reverse;

    cout << "Enter any string: ";
    for (int i = 0; i < SIZE; i++)
    {
        str[i] = getchar();
        if (str[i] == 10)
        {
            str[i] = NULL;
            break;
        }
    }
    reverse = reverseCase(str);
    cout << reverse;

    return 0;
}