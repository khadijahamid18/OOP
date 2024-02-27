#include <iostream>
using namespace std;

class Employee
{
    string firstName;
    string lastName;
    string SSN;

public:
    Employee(string fn, string ln, string sn)
    {
        this->firstName = fn;
        this->lastName = ln;
        this->SSN = sn;
    }

    void setFirstName(string fn)
    {
        this->firstName = fn;
    }

    string getFirstName()
    {
        return firstName;
    }

    void setLasttName(string ln)
    {
        this->lastName = ln;
    }

    string getLastName()
    {
        return lastName;
    }

    void setSSN(string sn)
    {
        this->SSN = sn;
    }

    string getSSN()
    {
        return SSN;
    }

    // Virtual Function
    virtual void print()
    {
        cout << "First Name: " << firstName << endl;
        cout << "Last Name: " << lastName << endl;
        cout << "Social Security Number: " << SSN << endl;
    }

    // Pure Virtual Function
    virtual double earnings() = 0;
};

class SalariedEmployee : public Employee
{
    double weeklySalary;

public:
    SalariedEmployee(string fn = "", string ln = "", string sn = "", double ws = 0) : Employee(fn, ln, sn)
    {
        this->weeklySalary = ws;
    }

    void setWeeklyEmployee(double salary)
    {
        this->weeklySalary = salary;
    }

    double getWeeklyEmployee()
    {
        return weeklySalary;
    }

    void print()
    {
        Employee::print();
        cout << "Weekly Saalary: " << weeklySalary << endl;
    }

    double earnings()
    {
        double earnings = 0;
        earnings = this->weeklySalary * 4;
        return earnings;
    }
};

class HourlyEmployee : public Employee
{
    double wage;
    double hours;

public:
    HourlyEmployee(string fn = "", string ln = "", string sn = "", double w = 0, double h = 0) : Employee(fn, ln, sn)
    {
        this->wage = w;
        this->hours = h;
    }

    void setWages(double w)
    {
        this->wage = w;
    }

    double getWages()
    {
        return wage;
    }

    void setHours(double h)
    {
        this->hours = h;
    }

    double getHours()
    {
        return hours;
    }

    void print()
    {
        Employee::print();
        cout << "Hours: " << hours << endl;
        cout << "Wages: " << wage << endl;
    }

    double earnings()
    {
        double earnings = 0;
        earnings = hours * wage;
        return earnings;
    }
};

class CommissionEmployee : public Employee
{
    double grossSales;
    double commissionRate;

public:
    CommissionEmployee(string fn = "", string ln = "", string sn = "", double gs = 0, double cr = 0) : Employee(fn, ln, sn)
    {
        this->grossSales = gs;
        this->commissionRate = cr;
    }

    void setGrossSales(double gs)
    {
        this->grossSales = gs;
    }

    double getGrossSale()
    {
        return grossSales;
    }

    void setCommissionRate(double cr)
    {
        this->commissionRate = cr;
    }

    double getCommissionRate()
    {
        return commissionRate;
    }

    void print()
    {
        Employee::print();
        cout << "Gross Sales: " << grossSales << endl;
        cout << "Commission Rate: " << commissionRate << endl;
    }

    virtual double earnings()
    {
        double earnings = 0;
        earnings = commissionRate * grossSales;
        return earnings;
    }
};

class BasePlusCommissionEmployee : public CommissionEmployee
{
    double baseSalary;

public:
    BasePlusCommissionEmployee(string fn = "", string ln = "", string sn = "", double gs = 0, double cr = 0, double bs = 0) : CommissionEmployee(fn, ln, sn, gs, cr)
    {
        this->baseSalary = bs;
    }

    void setBaseSalary(double bs)
    {
        this->baseSalary = bs;
    }

    double getBaseSalary()
    {
        return baseSalary;
    }

    void print()
    {
        CommissionEmployee::print();
        cout << "Base Salary: " << baseSalary << endl;
    }

    double earnings()
    {
        return CommissionEmployee::earnings() + baseSalary;
    }
};

int main()
{
    system("cls");

    SalariedEmployee obj2("Khadija", "Hamid", "56", 50.0);
    HourlyEmployee obj3("Fatima", "Amir", "13", 234.8, 56.0);
    CommissionEmployee obj4("Hadiya", "Bilal", "16", 4.6, 4.2);
    BasePlusCommissionEmployee obj5("Javeria", "Tariq", "76", 3.6, 2.6, 2.6);

    // Displaying Information

    obj2.print();
    cout << "Earnings: " << obj2.earnings() << endl;
    cout << endl;

    obj3.print();
    cout << "Earnings: " << obj3.earnings() << endl;
    cout << endl;

    obj4.print();
    cout << "Earnings: " << obj4.earnings() << endl;
    cout << endl;

    obj5.print();
    cout << "Earnings: " << obj5.earnings() << endl;
    cout << endl;

    // Creating pointer array of Employee type

    Employee *obj1[4];
    obj1[0] = &obj2;
    obj1[1] = &obj3;
    obj1[2] = &obj4;
    obj1[3] = &obj5;

    cout << "Pointers of Employee..." << endl << endl;  

    for (int i = 0; i < 4; i++)
    {
        obj1[i]->print();
        cout << "Salary: " << obj1[i]->earnings() << endl;
        cout << endl;
    }

    return 0;
}