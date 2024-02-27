#include <iostream>
using namespace std;

class Student
{
    int regNo;
    string firstName;
    string lastName;
    string program;
    float cgpa;

public:
    // Mutators = setters  AND   Commutators = getters

    void setRegNo(int reg)
    {
        if (reg >= 501 && reg <= 565)
        {
            regNo = reg;
        }
        else
        {
            regNo = 0;
        }
    }

    int getRegNo()
    {
        return regNo;
    }

    void setFirst(string f)
    {
        firstName = f;
    }

    string getFirst()
    {
        return firstName;
    }

    void setLast(string l)
    {
        lastName = l;
    }

    string getLast()
    {
        return lastName;
    }

    void setProgram(string prog)
    {
        program = prog;
    }

    string getProgram()
    {
        return program;
    }

    void setCgpa(float c)
    {
        if (c >= 0.0 && c <= 4.0)
        {
            cgpa = c;
        }
        else
        {
            cgpa = -1;
        }
    }

    float getCgpa()
    {
        return cgpa;
    }

    //  CONSTRUCTORS  and   DESTRUCTORS

    // Parameterized Constructor

    Student(int reg, string first, string last, string prog)
    {
        cout << "Parameterized Constructor..." << endl;
        setRegNo(reg);
        setFirst(first);
        setLast(last);
        setProgram(prog);
        setCgpa(-1);
    }

    Student(int reg, string first, string prog)
    {
        cout << "Constructors..." << endl;
        setRegNo(reg);
        setFirst(first);
        setProgram(prog);
        lastName = "";
        cgpa = -1;
    }

    Student(int reg, string first, string last, string prog, float cgpa)
    {
        setRegNo(reg);
        setFirst(first);
        setLast(last);
        setProgram(prog);
        setCgpa(cgpa);
    }

    // Copy Constructor

    Student(const Student &obj)
    {
        cout << "Copy Constructors..." << endl;
        regNo = obj.regNo;
        firstName = obj.firstName;
        lastName = obj.lastName;
        program = obj.program;
        cgpa = obj.cgpa;
    }

    ~Student()
    {
        cout << "Destructor Executed..." << endl;
    }

    // Member Function

    void setStudent(int r, string f, string l, string p, float c)
    {
        setRegNo(r);
        setFirst(f);
        setLast(l);
        setProgram(p);
        setCgpa(c);
    }

    // Read method

    void readStudent()
    {
        cout << "Please enter the student's registration number: ";
        cin >> regNo;
        setRegNo(regNo);

        cout << "Please enter the student's first name: ";
        cin >> firstName;
        setFirst(firstName);

        cout << "Please enter the student's last name: ";
        cin >> lastName;
        setLast(lastName);

        cout << "Please enter the student's program: ";
        cin >> program;
        setProgram(program);

        cout << "Please enter the student's cgpa: ";
        cin >> cgpa;
        setCgpa(cgpa);

        cout << endl;
    }

    // Write Method

    void writeStudent()
    {
        cout << "Reg No: " << regNo << "\t\t"
             << "Fist name: " << firstName << "\t\t"
             << "Last Name: " << lastName << "\t\t"
             << "Program: " << program << "\t\t"
             << "Cgpa: " << cgpa << endl;
    }

    bool isFirstSemester()
    {
        if (cgpa == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    float getPercentage()
    {
        if (cgpa >= 0)
        {
            return (cgpa / 4) * 100;
        }
        else
        {
            return -1;
        }
    }

    bool isPromoted()
    {
        if (cgpa >= 2.0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()
{
    system("cls");
    Student a(1, "Khadija", "Hamid", "BSIT", 3.78);
    // Student obj2(obj1);
    Student b(3, "Hadiya", "SE");

    b.setLast("Bilal");
    b.setCgpa(3);

    Student c(510, "Dija", "Sara", "CS");
    c.setStudent(515, "Ali", "Ahmed", "IT", 3.6);

    Student d(a);
    d.readStudent();

    cout << endl;

    cout << "Reg No  \t\t  First Name  \t\t  Last Name  \t\t  Program  \t\t  CGPA \n";
    a.writeStudent();
    b.writeStudent();
    c.writeStudent();

    cout << d.getRegNo() << "\t\t" << d.getFirst() << "\t\t" << d.getLast() << "\t\t" << d.getProgram() << "\t\t" << d.getCgpa();

    cout << endl;

    cout << "Is IT Student in first semester ? " << a.isFirstSemester() << endl;
    cout << "Percentage of CGPA: " << b.getPercentage() << endl;
    cout << "Is Student Promoted: " << a.isPromoted() << endl;

    // obj1.isFirstSemester();
    // obj1.getPercentage();
    // obj1.isPromoted();

    // obj2.readStudent();
    // obj2.writeStudent();
    // obj2.isFirstSemester();
    // obj2.getPercentage();
    // obj2.isPromoted();

    return 0;
}
