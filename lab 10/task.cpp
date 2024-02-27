#include "iostream"
#include <math.h>
using namespace std;

class FeetInches
{
private:
    int feet;   // To hold a number of feet
    int inches; // To hold a number of inches

    void simplify()
    {
        if (inches >= 12)
        {
            feet += (inches / 12);
            inches = inches % 12;
        }
        else if (inches < 0)
        {
            feet -= ((abs(inches) / 12) + 1); // abs = absolute value (conver -ve value to +ve)
            inches = 12 - (abs(inches) % 12);
        }
    }

public:
    // Constructor
    FeetInches(int f = 0, int i = 0)
    {
        feet = f;
        inches = i;
        simplify();
    }

    FeetInches(const FeetInches &right)
    {
        feet = right.feet;
        inches = right.inches;
        simplify();
    }

    // Mutator functions
    void setFeet(int f)
    {
        feet = f;
    }

    void setInches(int i)
    {
        inches = i;
        simplify();
    }

    // Accessor functions
    int getFeet() const
    {
        return feet;
    }

    int getInches() const
    {
        return inches;
    }

    FeetInches operator+(const FeetInches &right)
    {
        FeetInches temp;

        temp.inches = inches + right.inches;
        temp.feet = feet + right.feet;
        temp.simplify();

        return temp;
    }

    FeetInches operator-(const FeetInches &right)
    {
        FeetInches temp;

        temp.inches = inches - right.inches;
        temp.feet = feet - right.feet;
        temp.simplify();

        return temp;
    }

    FeetInches operator*(const FeetInches &right)
    {
        FeetInches temp;

        temp.inches = inches * right.inches;
        temp.feet = feet * right.feet;
        temp.simplify();

        return temp;
    }

    FeetInches operator++()
    {
        ++inches;
        simplify();

        return *this;
    }

    FeetInches operator++(int)
    {
        FeetInches temp(feet, inches);

        inches++;
        simplify();

        return temp;
    }

    FeetInches operator--()
    {
        --inches;
        simplify();

        return *this;
    }

    FeetInches operator--(int)
    {
        FeetInches temp(feet, inches);

        inches--;
        simplify();

        return temp;
    }

    bool operator>(const FeetInches &right)
    {
        bool status;

        if (feet > right.feet)
            status = true;
        else if (feet == right.feet && inches > right.inches)
            status = true;
        else
            status = false;

        return status;
    }

    bool operator<(const FeetInches &right)
    {
        return !(*this > right);
    }

    bool operator>=(const FeetInches &right)
    {
        bool status;

        if (feet >= right.feet)
            status = true;
        else if (feet == right.feet && inches >= right.inches)
            status = true;
        else
            status = false;

        return status;
    }

    bool operator<=(const FeetInches &right)
    {
        return !(*this >= right);
    }

    bool operator==(const FeetInches &right)
    {
        bool status;

        if (feet == right.feet && inches == right.inches)
            status = true;
        else
            status = false;

        return status;
    }

    bool operator!=(const FeetInches &right)
    {
        return !(*this == right);
    }

    friend ostream &operator<<(ostream &, const FeetInches &);
    friend istream &operator>>(istream &, FeetInches &);
};

ostream &operator<<(ostream &out, const FeetInches &obj)
{
    out << "Feet = " << obj.feet << "\tInches = " << obj.inches << endl;

    return out;
}

istream &operator>>(istream &in, FeetInches &obj)
{
    cout << "Enter Feet:\t";
    in >> obj.feet;

    cout << "Enter Inches:\t";
    in >> obj.inches;

    return in;
}

class RoomDimension
{
    FeetInches length;
    FeetInches width;

public:
    void setLength(FeetInches length)
    {
        this->length.setFeet(length.getFeet());
        this->length.setInches(length.getInches());
    }

    FeetInches getLength() const
    {
        return length;
    }

    void setWidth(FeetInches width)
    {
        this->width.setFeet(width.getFeet());
        this->width.setInches(width.getInches());
    }

    FeetInches getWidth() const
    {
        return width;
    }

    // RoomDimension()
    // {

    // }

    RoomDimension(FeetInches length, FeetInches width)
    {
        this->length.setFeet(length.getFeet());
        this->length.setInches(length.getInches());

        this->width.setFeet(width.getFeet());
        this->width.setInches(width.getInches());

        cout << "Room Constructor" << endl;
    }

    FeetInches getArea()
    {
        FeetInches area;
        area = this->width * this->length;
        return area;
    }

    void display()
    {
        cout << "Length: " << this->length << endl;
        cout << "Width: " << this->width << endl;
    }
};

class RoomCarpet
{
    RoomDimension roomSize;
    float costPerSquareFoot;

public:
    void setRoomSize(RoomDimension roomSize)
    {
        this->roomSize = roomSize;
    }

    RoomDimension getRoomSize()
    {
        return this->roomSize;
    }

    void setCostPerSquareFoot(float costPerSquareFoot)
    {
        this->costPerSquareFoot = costPerSquareFoot;
    }

    float getCostPerSquareFoot()
    {
        return costPerSquareFoot;
    }

    RoomCarpet(RoomDimension r, float c) : roomSize(r.getLength(), r.getWidth())
    {
        setCostPerSquareFoot(c);   
    }

    float getTotalCost()
    {
        FeetInches area = roomSize.getArea();
        float totalCost = (area.getFeet() * area.getInches() * costPerSquareFoot);
        return totalCost;
    }

    void display() 
    {
        roomSize.display();
        cout << "Cost per square foot: Rs. " << costPerSquareFoot << endl;
    }
};

int main()
{
    system("cls");
    cout << "Enter the dimensions of room in feet and inches: " << endl;
    FeetInches length, width;
    cout << "Length: ";
    cin >> length;
    cout << "Width: ";
    cin >> width;

    cout << "Enter cost pr square foot of carpet: ";
    float costPerSquareFoot;
    cin >> costPerSquareFoot;

    RoomDimension roomDim(length, width);
    RoomCarpet roomCar(roomDim, costPerSquareFoot);

    roomCar.display();
    cout << "Total cost of the carpet: Rs. " << roomCar.getTotalCost() << endl;


    return 0;
}