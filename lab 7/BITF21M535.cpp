#include <iostream>
#include <string>
using namespace std;

class Date
{
private:
    int day;
    int month;
    int year;

public:

    void setDay(int day)
    {
        if (day >= 1 && day <= 31)
        {
            this->day = day;
        }
        else
        {
            this->day = 1;
        }
    }

    int getDay() const
    {
        return day;
    }

    void setMonth(int month)
    {
        if (month >= 1 && month <= 12)
        {
            this->month = month;
        }
        else
        {
            this->month = month;
        }
    }

    int getMonth() const
    {
        return month;
    }

    void setYear(int year)
    {
        if (year >= 1900)
        {
            this->year = year;
        }
        else
        {
            this->year = 1900;
        }
    }

    int getYear() const
    {
        return year;
    }
    // Constructors and Destructors

    Date(int day, int month, int year)
    {
        setDay(day);
        setMonth(month);
        setYear(year);
    }

    Date(int month, int year)
    {
        this->day = 1;
        setMonth(month);
        setYear(year);
    }

    Date()
    {
        this->day = 1;
        this->month = 1;
        this->year = 1900;
    }

    ~Date()
    {
        // cout << "Date object is destroyed" << endl;
    }

    // Overloaded operators

    Date operator++()
    { // pre-increment
        if (day == 31 && month == 12)
        { 
            day = 1;
            month = 1;
            year++;
        }
        else if (day == 31)
        { 
            day = 1;
            month++;
        }
        else
        {
            day++;
        }
        return *this;
    }

    Date operator++(int)
    { // post-increment
        Date temp = *this;
        ++(*this);
        return temp;
    }

    Date operator--()
    { // pre-decrement
        if (day == 1 && month == 1)
        { 
            day = 31;
            month = 12;
            year--;
        }
        else if (day == 1)
        { 
            month--;
            if (month == 2)
            {
                if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
                { // leap year 
                    day = 29;
                }
                else
                {
                    day = 28;
                }
            }
            else if (month == 4 || month == 6 || month == 9 || month == 11)
            {
                day = 30;
            }
            else
            {
                day = 31;
            }
        }
        else
        {
            day--;
        }
        return *this;
    }

    Date operator--(int)
    { // post-decrement
        Date temp = *this;
        --(*this);
        return temp;
    }

    int operator-(const Date &d)
    { // subtraction
        int count = 0;
        Date first = d;
        Date last = *this;
        while (first < last)
        {
            ++first;
            count++;
        }
        return count;
    }

    bool operator<(const Date &obj)
    {
        if (year < obj.year)
        {
            return true;
        }
        else if (year == obj.year && month < obj.month)
        {
            return true;
        }
        else if (year == obj.year && month == obj.month && day < obj.day)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool operator+()
    { // addition
        if (month == 2 && day == 5)
        { 
            return true;
        }
        else if (month == 3 && day == 23)
        { 
            return true;
        }
        else if (month == 5 && day == 1)
        { 
            return true;
        }
        else if (month == 8 && day == 14)
        { 
            return true;
        }
        else if (month == 9 && day == 6)
        { 
            return true;
        }
        else
        {
            return false;
        }
    }

    

    friend ostream &operator<<(ostream &out, const Date &obj);
    friend istream &operator>>(istream &in, Date &obj);
};

ostream &operator<<(ostream &out, const Date &obj)
{
    string months[] = { "January ", " February ", " March ", " April ", " May ", " June ", " July ", " Augest ", " September ", " October ", " November ", " December "};
    out << months[obj.getMonth() - 1] << " " << obj.getDay() << "," << obj.getYear() << endl;
    return out;
}

istream &operator>>(istream &in, Date &obj)
{
    char c;

    // cout << "Enter the Date / Month / Year: " << endl;
    in >> obj.day >> c >> obj.month >> c >> obj.year;
    obj.setDay(obj.day);
    obj.setMonth(obj.month);
    obj.setYear(obj.year);

    return in;
}

int main()
{
    system("cls");
    Date obj(10, 4, 2023);
    cout << obj << endl; // display date in the form April 10, 2023

    Date d1, d2;
    cout << "Enter the first date in this order dd/mm/yyyy: ";
    cin >> d1;
    cout << "Enter the second date in this order dd/mm/yyyy: ";
    cin >> d2;
    cout << "Number of days between two dates: " << d2 - d1 << endl;

    ++obj;
    cout << obj << endl;

    obj++;
    cout << obj << endl;

    --obj;
    cout << obj << endl;

    obj--;
    cout << obj << endl;

    

    return 0;
}