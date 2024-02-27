#include <iostream>
using namespace std;

class Student
{
    string a;
    int b;

public:
    Student()
    {
    }

    void input()
    {
        cout << "Enter the Name: ";
        cin >> this->a;
        cout << "Enter the Roll number: ";
        cin >> this->b;

        cout << endl;
    }

    void print()
    {
        cout << this->a << "\t\t" << this->b << endl;
    }
};
int main()
{
    system("cls");

    // STACK

    Student arr[] = {Student(), Student(), Student()};

    for (int i = 0; i < 3; i++)
    {
        arr[i].input();
    }

    for (int i = 0; i < 3; i++)
    {
        arr[i].print();
    }

    return 0;
}