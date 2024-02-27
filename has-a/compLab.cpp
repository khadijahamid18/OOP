#include <iostream>
using namespace std;

class numdays
{
    float hours;

public:
    // contructor
    numdays(int h)
    {
        hours = h;
    }

    // functions
    void sethours(float h)
    {
        hours = h;
    }

    float gethours()
    {
        return hours;
    }

    void setdays(float d)
    {
        hours = d * 8;
    }

    float getdays()
    {
        float day = hours / 8;
        return day;
    }

    // operators
    numdays operator+(const numdays &obj) const
    {
        numdays temp(hours + obj.hours);
        return temp;
    }

    numdays operator-(const numdays &obj) const
    {
        numdays temp(hours - obj.hours);
        return temp;
    }

    numdays operator++()
    {
        this->hours++;
        return *this;
    }

    numdays operator++(int)
    {
        numdays old(hours);
        hours++;
        return old;
    }

    numdays operator--()
    {
        this->hours--;
        return *this;
    }

    numdays operator--(int)
    {
        numdays old(hours);
        this->hours--;
        return old;
    }
};