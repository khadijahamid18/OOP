#include <iostream>
using namespace std;

class Square
{
    int length;

public:
    Square(int l) : length(l)
    {
    }

    void setLength(int l)
    {
        length = l;
    }

    int getLength()
    {
        return length;
    }

    void printSquare()
    {
        cout << "Length: " << length << endl;
    }
};

class Rectangle
{
    int length, height;

public:
    Rectangle(int l, int h)
    {
        length = l;
        height = h;
    }

    void setLength(int l)
    {
        length = l;
    }

    int getLength()
    {
        return length;
    }

    void setHeight(int h)
    {
        height = h;
    }

    int getHeight()
    {
        return height;
    }

    void printRectangle()
    {
        cout << "Length: " << length << endl
             << "Height: " << height << endl;
    }

    Rectangle operator+(const Rectangle &obj)
    {
        Rectangle temp(length + obj.length, height + obj.height);
        return temp;
    }

    Rectangle operator+=(const Rectangle &obj)
    {
        this->length += obj.length;
        this->height += obj.height;

        return *this;
    }

    Rectangle operator-()
    {
        length *= -1;
        height *= -1;

        return *this;
    }

    Rectangle operator++() // Pre increment 
    {
        length++;
        height++;

        return *this;
    }

    Rectangle operator++(int) // Post increment
    {
        Rectangle temp(*this);
        length++;
        height++;

        return temp;
    }
};

ostream &operator<<(ostream &out, Rectangle &obj)
{
    out << obj.getHeight() << "		" << obj.getLength() << endl;
    return out;
}

int main()
{
    Rectangle r1(5, 10), r2(2, 4), r3(1, 2);
    // r2 << cout;
    // cout << r1;		// operator<<(cout, r1)

    operator<<(cout, r1) << r2; // cout << Rectangle
    cout << r1 << r2 << r3;

    // Rectangle res = r1 + r2;	// r1.operator+(r2)
    // r1.operator+(r2).operator+(r3).printRectangle();
    // res.printRectangle();

    //(r1 += r2 += r3).printRectangle();		//  res = r1 = r1 + r2
    // Rectangle res1 = -r1;
    //(-r1).printRectangle();
    // r1.printRectangle();

    /*Rectangle res2 = ++r1;
    r1.printRectangle();
    res2.printRectangle();*/

    /*Rectangle res3 = r1++;
    r1.printRectangle();
    res3.printRectangle();
    */

    // cout << r1;
}