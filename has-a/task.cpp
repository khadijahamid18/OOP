#include <iostream>
using namespace std;

class Computer
{
    int compId;
    int price;

public:
    Computer()
    {
        this->compId = -1;
        this->price = -1;
        cout << "Default constructor of class Computer!" << endl;
    }

    Computer(int id, int price)
    {
        this->compId = id;
        this->price = price;
        cout << "Parameterized constructor of class Computer!" << endl;
    }

    Computer(const Computer& obj) 
    {
        this->compId = obj.compId;
        this->price = obj.price;
        cout << "Copy Constructor of class Computer!" << endl;
    }

    ~Computer()
    {
        cout << "Destructor of class Computer" << endl;
    }

    void print()
    {
        cout << "Computer ID: " << compId << endl;
        cout << "Computer price: " << price << endl;
    }
};

class CPU
{
    int cpuId;
    float cpuSpeed;
    Computer price;

public:
    CPU() 
    {
        this->cpuId = -1;
        this->cpuSpeed = -1;
        cout << "Default constructor of class CPU!" << endl;
    }

    CPU(int id, float speed, int cId, int p) : price(cId, p)  
    {
        this->cpuId = id;
        this->cpuSpeed = speed;
        cout << "Parameterized constructor of class CPU!" << endl;
    }

    CPU (const CPU& obj) : price(obj.price)
    {
        this->cpuId = obj.cpuId;
        this->cpuSpeed = obj.cpuSpeed;
        cout << "Copy Constructor of class CPU!" << endl;
    }

    ~CPU()
    {
        cout << "Destructor of class CPU" << endl;
    }

    void print()
    {
        cout << "CPU ID: " << cpuId << endl;
        cout << "CPU speed: " << cpuSpeed << endl;

        price.print();
    }
};

int main()
{
    system("cls");
    // CPU c1; // //firstly computer's object will be build then CPU's object will 
    CPU c1(2, 6.6, 6, 3);
    c1.print();

    return 0;
}