#include <iostream>
using namespace std;

class Person
{
    int age;
    string name;
    string address;
    string phoneNo;
    string email;
};

class Student
{
    float cgpa;
    int semester;
    int id;
    string *courses;
};

// DRY ---> Don't Repeat Yourself
class Teacher
{
    float income;
    int publications;
};

class Counter
{
protected:
    int count;

public:
    Counter()
    {
        cout << "Counter:   Default Constructor\n";
        count = 0;
    }

    Counter(int c)
    {
        cout << "Counter:   Parametric Constructor\n";
        count = c;
    }

    Counter(const Counter &obj)
    {
        cout << "Counter:   Copy Constructor\n";
        count = obj.count;
    }

    ~Counter()
    {
        cout << "Counter:   Destructor!\n\n";
    }

    void print()
    {
        cout << count << endl;
    }

    int increment()
    {
        return ++count;
    }
};

class DownC : public Counter
{

public:
    DownC() : Counter()
    {
        cout << "DownC:   Default Constructor\n\n";
    }

    DownC(int c) : Counter(c)
    {
        cout << "DownC:   Parametric Constructor\n\n";
    }

    DownC(const DownC &obj) : Counter(obj)
    {
        cout << "DownC:   Copy Constructor\n\n";
    }

    ~DownC()
    {
        cout << "DownC:   Destructor!\n";
    }

    int decrement()
    {
        return --this->count;
    }
};

// Counter   ----> count ,      print() , increment()
// DownC    -----> x, count,    print(), increment(), decrement()

DownC fun(Counter obj)
{
    return DownC(19);
}

int main()
{
    // d1 has two datatypes Counter & DownC      Counter  ----> DownC
    //  DownC ----> Counter
    // Counter c1;

    DownC d1(10), d2(d1);
    // DownC res = fun(c1);
    // fun(d1);
    // cout << sizeof(d1) << endl;
    // d1.count = 10;
    // d1.print();
    // cout << d1.decrement() << endl;

    return 0;
}