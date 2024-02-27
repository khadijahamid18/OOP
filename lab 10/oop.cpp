#include <iostream>
using namespace std;

class FeetInches
{
private:
    int feet;
    int inches;
public:
    void setFeet(int f)
    {
        feet = f;
    }
    void setInches(int i)
    {
        inches = i;
    }
    int getFeet() const
    {
        return feet;
    }
    int getInches() const
    {
        return inches;
    }
};

class RoomDimension
{
private:
    FeetInches length;
    FeetInches width;
public:
    RoomDimension(FeetInches l, FeetInches w)
    {
        length = l;
        width = w;
    }
    void setLength(FeetInches l)
    {
        length = l;
    }
    void setWidth(FeetInches w)
    {
        width = w;
    }
    FeetInches getLength() const
    {
        return length;
    }
    FeetInches getWidth() const
    {
        return width;
    }
    FeetInches getArea() const
    {
        FeetInches area;
        int feet = length.getFeet() * width.getFeet();
        int inches = length.getInches() * width.getInches();
        if (inches >= 12)
        {
            feet += inches / 12;
            inches %= 12;
        }
        area.setFeet(feet);
        area.setInches(inches);
        return area;
    }
    void display() const
    {
        cout << "Length: " << length.getFeet() << "' " << length.getInches() << "\"" << endl;
        cout << "Width: " << width.getFeet() << "' " << width.getInches() << "\"" << endl;
    }
};

class RoomCarpet
{
private:
    RoomDimension roomSize;
    float costPerSquareFoot;
public:
    RoomCarpet(RoomDimension rd, float c)
    {
        roomSize = rd;
        costPerSquareFoot = c;
    }
    void setRoomSize(RoomDimension rd)
    {
        roomSize = rd;
    }
    void setCostPerSquareFoot(float c)
    {
        costPerSquareFoot = c;
    }
    RoomDimension getRoomSize() const
    {
        return roomSize;
    }
    float getCostPerSquareFoot() const
    {
        return costPerSquareFoot;
    }
    float getTotalCost() const
    {
        FeetInches area = roomSize.getArea();
        float totalCost = (area.getFeet() * area.getInches() * costPerSquareFoot) / 144.0;
        return totalCost;
    }
    void display() const
    {
        roomSize.display();
        cout << "Cost per square foot: Rs. " << costPerSquareFoot << endl;
    }
};

int main()
{
    int lengthFeet, lengthInches, widthFeet, widthInches;
    float costPerSquareFoot;
    cout << "Enter length of the room in feet and inches (separated by a space): ";
    cin >> lengthFeet >> lengthInches;
    cout << "Enter width of the room in feet and inches (separated by a space): ";
    cin >> widthFeet >> widthInches;
    cout << "Enter cost per square foot of carpeting: Rs. ";
    cin >> costPerSquareFoot;
    FeetInches length, width;
    length.setFeet(lengthFeet);

}    