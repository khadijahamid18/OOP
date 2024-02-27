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

    // HEAP

    Student *ptr = new Student[3];

    for (int i = 0; i < 3; i++)
    {
        ptr[i].input();
    }

    for (int i = 0; i < 3; i++)
    {
        ptr[i].print();
    }

    delete[] ptr;
    
    return 0;
}