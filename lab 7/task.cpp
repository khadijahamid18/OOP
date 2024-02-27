#include <iostream>
using namespace std;

class Date
{
    int day;
    int month;
    int year;

public:
    // Setters and getters

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

    // Member Functions

    Date operator++() // Pre increment
    {
        day++;
        if (day > 31)
        {
            day = 1;
            month++;
            if (month > 12)
            {
                month = 1;
                year++;
            }
        }
        return *this;
    }

    Date operator++(int) // Post Decrement
    {
        Date temp(*this);
        day++;
        if (day > 31)
        {
            day = 1;
            month++;
            if (month > 12)
            {
                month = 1;
                year++;
            }
        }
        return temp;
    }

    Date operator--() // Pre Decrement
    {
        day--;
        if (day < 1)
        {
            day = 31;
            month--;
            if (month < 1)
            {
                month = 12;
                year--;
            }
        }
        return *this;
    }

    Date operator--(int) // Post Decrement
    {
        Date temp(*this);
        if (day < 1)
        {
            day = 31;
            month--;
            if (month < 1)
            {
                month = 12;
                year--;
            }
        }
        return temp;
    }

    int operator-(const Date &obj)
    {
        int day = 0;
        int month = 0;
        int year = 0;
        day = this->day - obj.day;
        month = this->month - obj.month;
        year = this->year - obj.year;

        return (year * 372) + (month * 31) + day;
    }

    // int operator-(const Date &obj)
    // {
    //     int count = 0;
    //     Date start = obj;
    //     Date end = *this;
    //     while (start < end)
    //     {
    //         ++start;
    //         count++;
    //     }
    //     return count;
    // }

    // bool operator<(const Date &d)
    // {
    //     if (year < d.year)
    //     {
    //         return true;
    //     }
    //     else if (year == d.year && month < d.month)
    //     {
    //         return true;
    //     }
    //     else if (year == d.year && month == d.month && day < d.day)
    //     {
    //         return true;
    //     }
    //     else
    //     {
    //         return false;
    //     }
    // }

    bool operator+()
    { // addition
        if ((month == 2 && day == 5) || (month == 3 && day == 23) || (month == 5 && day == 1))
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
    string months[] = {" ", "January ", " February ", " March ", " April ", " May ", " June ", " July ", " Augest ", " September ", " October ", " November ", " December "};
    out << months[obj.getMonth()] << " " << obj.getDay() << "," << obj.getYear() << endl;
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
    Date d(1, 1, 2000);
    Date d1, d2;

    cout << "Enter the first date in the format dd/mm/yyyy: ";
    cin >> d1;
    cout << "Enter the second date in the format dd/mm/yyyy: ";
    cin >> d2;
    cout << "Number of days between two dates: " << d2 - d1 << endl;

    ++d;
    cout << d << endl;

    d++;
    cout << d << endl;

    --d;
    cout << d << endl;

    d--;
    cout << d << endl;

    if (+d)
    {
        cout << "The given date is a public holiday" << endl;
    }
    else
    {
        cout << "The given date is not a public holiday" << endl;
    }

    return 0;
}