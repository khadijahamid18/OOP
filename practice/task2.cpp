#include <iostream>
using namespace std;

class Student
{
public:
    int roll;
    string name;

    Student()
    {
    }

    Student(int roll, string name)
    {
        this->name = name;  // this is to access the object
        this->roll = roll;
    }

    void print()
    {
        cout << this->name << "     " << this->roll << endl;
    }
};

int main()
{

    system("cls");
    // int ar[] = {1, 2, 3};

    Student arr[] = {Student(510, "Ali"), Student(513, "CD"), Student(520, "XY")};

    // STACK

    for (int i = 0; i < 3; i++)
    {
        (arr[i]).print();
    }


    // HEAP

    Student *ptr = new Student[2];

    (*ptr).name = "Abc";   // *ptr mn arr ki first value hy  ptr hota to address hota
    (*ptr).roll = 541;     // *ptr se dereference hota to object ban jata jis ko dot operator se access krty

    ptr[1].name = "XYZ";
    ptr[1].roll = 1234;

    // // cout << ptr[0].name << "    " << ptr[0].roll << endl;
    // for (int i = 0; i < 2; i++)
    // {
    //     cout << ptr[i].name << "\t\t" << ptr[i].roll << endl;
    // }
    cout << (*(ptr + 1)).name << "      " << (*(ptr + 1)).roll << endl;  // line 57 and 58 are same
    cout << (ptr + 1)->name << "   " << (ptr + 1)->roll << endl;

    // cout << ptr << endl;

    delete[] ptr;

    // Student *ptr = &st1;

    // cout << ptr->name << endl;

    //     int ival = 2048;

    //     int *iptr = NULL;
    //     double *dptr = NULL;

    //     ival = *iptr;
    //     *iptr = &ival; // No --> storing address in integer, dereferncing a NULL ptr

    //     ival = iptr; // No --> assigning pointer(address) to an integer
    //     iptr = &ival;

    //     *iptr = ival;
    //     dptr = iptr;  // No --> int* = double*
    //     iptr = ival;  // No --> storing value inside a pointer
    //     dptr = *iptr; // No --> storing value inside a pointer

    return 0;
}