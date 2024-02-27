#include <iostream>
using namespace std;

class Employee
{
private:
    string name;
    int id;
    string department;
    string position;

public:
    Employee(string employeeName, int employeeID, string employeeDepartment, string employeePosition)
    {
        cout << "Constructor..." << endl;
        employeeName = name;
        employeeID = id;
        employeeDepartment = department;
        employeePosition = position;
    }

    Employee(string employeeName, int employeeID)
    {
        employeeName = name;
        employeeID = id;
        department = "";
        position = "";
    }

    Employee()
    {
        cout << "Default Constructor..." << endl;
        name = "";
        department = "";
        position = "";
        id = 0;
    }

    Employee(const Employee &obj)
    {
        cout << "Copy Constructor..." << endl;
        name = obj.name;
        id = obj.id;
        department = obj.department;
        position = obj.position;
    }

    ~Employee()
    {
        cout << "Destructor..." << endl;
    }

    // Getters and Setters

    void setName(string n)
    {
        name = n;
    }

    string getName()
    {
        return name;
    }

    void setId(int roll)
    {
        id = roll;
    }

    int getId()
    {
        return id;
    }

    void setDepartment(string dept)
    {
        department = dept;
    }

    string getDepartment()
    {
        return department;
    }

    void setPosition(string post)
    {
        position = post;
    }

    string getPosition()
    {
        return position;
    }

    // Implementation of Member Functions

    void setInfo(string employeeName, int employeeID, string employeeDepartment, string employeePosition)
    {
        setName(employeeName);
        setId(employeeID);
        setDepartment(employeeDepartment);
        setPosition(employeePosition);
    }

    int getInfo() 
    {
        cout << "Enter employee's name: ";
        cin >> name;
        setName(name);

        cout << "Enter employee's ID: ";
        cin >> id;
        setId(id);

        cout << "Enter employee's department: ";
        cin >> department;
        setDepartment(department);

        cout << "Enter employee's position: ";
        cin >> position;
        setPosition(position);

        cout << endl;
    }

    void putInfo()
    {
        // cout << "Employee's name: " << name << endl;
        // cout << "Employee's ID: " << id << endl;
        // cout << "Employee's department: " << department << endl;
        // cout << "Employee's position: " << position << endl;

        cout << "Name: " << name << "\t\t"
             << "ID: " << id << "\t\t"
             << "Department: " << department << "\t\t"
             << "Position: " << position << endl;
    }
};

int main()
{
    system("cls");
    Employee obj1("Naveed Ali", 1230, "Computer Science", "Assistant Professor");
    Employee obj2("Nouman Abdullah", 1231, "Software Engineering", "Lecturer");
    Employee obj3(obj1);
    Employee obj4("Nadia", 1242, "Information Technology", "Assistant Professor");
    Employee obj5(obj4);

    obj1.getInfo();
    obj2.getInfo();
    obj3.getInfo();
    obj4.getInfo();
    obj5.getInfo();

    cout << endl;

    // cout << "Name: "
    //      << "\t"
    //      << "ID: "
    //      << "\t"
    //      << "Department: "
    //      << "\t"
    //      << "Position: " << endl;

    obj1.putInfo();
    obj2.putInfo();
    obj3.putInfo();
    obj4.putInfo();
    obj5.putInfo();

    return 0;
}