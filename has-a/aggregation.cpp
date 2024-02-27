
#include "iostream"

using namespace std;

class Teacher
{
    int eCode;
    string tName;

public:
    Teacher(int eCode, string tName)
    {
        this->eCode = eCode;
        this->tName = tName;
    }

    void teacherInfo()
    {
        cout << "e-code = " << eCode << "\tt-name = " << tName << endl;
    }
};

class Department
{
    int dNo;
    string dName;

    Teacher *teacher; // holds a reference to Teacher : Aggregation (week binding)

public:
    Department(int dNo, string dName, Teacher *teacher)
    {
        this->dNo = dNo;
        this->dName = dName;

        this->teacher = teacher; // data member teacher holds the reference/address of a Teacher
    }

    void departmentInfo()
    {
        cout << "d-no = " << dNo << "\td-name = " << dName << endl;

        if (teacher != NULL)        // if teacher exists
            teacher->teacherInfo(); // display teacher information
    }
};

int main()
{
    Teacher t(100, "Khan");

    Department d(1, "DIT", &t); //&t reference of teacher 

    d.departmentInfo();

    return 0;
}