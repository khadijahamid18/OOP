
#include "iostream"
#include "string"

using namespace std;

class CPU
{
    int model;
    string name;

public:
    CPU()
    {
        this->model = -1;
        this->name = "";
    }

    CPU(int model, string name)
    {
        this->model = model;
        this->name = name;
    }

    CPU(const CPU &obj)
    {
        model = obj.model;
        name = obj.name;
    }

    ~CPU()
    {
        cout << "CPU Destructor." << endl;
    }

    void printInfo()
    {
        cout << "CPU Model = " << model << "\tCPU Name = " << name << endl;
    }
};

class Computer
{
    int makeYear;
    string name;

    // composition (has-a relationship. Computer "has-a" CPU)
    CPU m_cpu; // CPU's object is composed in Computer. The life cycle of m_cpu depends on Computer's Object.

public:
    // default constuctor of CPU will be executed
    Computer()
    {
        this->makeYear = -1;
        this->name = "";
    }

    // making a call to Parameterzied constructor of CPU "m_cpu(cpuCode, cpuName)". Default constructor will be executed, otherwise.
    Computer(int computerMakeYear, string computerName, int cpuCode, string cpuName) : m_cpu(cpuCode, cpuName)
    {
        makeYear = computerMakeYear;
        name = computerName;
    }

    // making a call to copy constructor of CPU "m_cpu(obj.m_cpu)". Default constructor will be executed, otherwise.
    Computer(const Computer &obj) : m_cpu(obj.m_cpu)
    {
        makeYear = obj.makeYear;
        name = obj.name;
    }

    ~Computer()
    {
        cout << "Computer Destructor." << endl;
    }

    // display the data of computer
    void printInfo()
    {
        cout << "Computer Make Year = " << makeYear << "\t Computer Name = " << name << endl;

        m_cpu.printInfo(); // making a call to CPU's printInfo to display the data
    }
};

int main()
{
    // Computer c1(1, "Dija", 3, "hello");
    // c1.printInfo();

    CPU c2(2, "hey");
    c2.printInfo();

    return 0;
}
