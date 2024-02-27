#include <iostream>
using namespace std;

class Circle
{
    int x;
    int y;
    float radius;
    static const double PI;

public:
    // Mutators or setters AND accessor or getters

    void setX(int x)
    {
        if (x >= -50 && x <= 50)
        {
            this->x = x;
        }
        else
        {
            this->x = 0;
        }
    }
    int getX()
    {
        return this->x;
    }

    void setY(int y)
    {
        if (y >= -50 && y <= 50)
        {
            this->y = y;
        }
        else
        {
            this->y = 0;
        }
    }
    int getY()
    {
        return this->y;
    }

    void setRadius(float radius)
    {
        if (radius >= 1 && radius <= 10)
        {
            this->radius = radius;
        }
        else
        {
            this->radius = 5;
        }
    }

    float getRadius()
    {
        return this->radius;
    }

    // Constructors AND Destructors

    Circle(int x, int y, float radius)
    {
        cout << "Parameterized Constructor..." << endl;
        setX(x);
        setY(y);
        setRadius(radius);
    }

    Circle(int x, int y)
    {
        cout << "Parameterized Constructor..." << endl;
        setX(x);
        setY(y);
        this->radius = 0;
    }

    Circle(int x, float radius)
    {
        cout << "Parameterized Constructor..." << endl;
        setX(x);
        setRadius(radius);
        this->y = 0;
    }

    Circle() // : c(0)
    {
        cout << "Default Constructor..." << endl;
        this->x = 0;
        this->y = 0;
        this->radius = 0;
    }

    Circle(const Circle &obj) // : c(obj.c)
    {
        cout << "Copy Constructor..." << endl;
        this->x = obj.x;
        this->y = obj.y;
        this->radius = obj.radius;
    }

    ~Circle()
    {
        cout << "Destructor executed..." << endl;
    }

    // Member Function

    void setCircle(int x, int y, float radius)
    {
        setX(x);
        setY(y);
        setRadius(radius);
    }

    void getCircle()
    {
        cout << "Please enter the circle's x-axis: ";
        cin >> this->x;
        setX(x);

        cout << "Please enter the circle's y-axis: ";
        cin >> this->y;
        setY(y);

        cout << "Please enter the circle's radius: ";
        cin >> this->radius;
        setRadius(radius);

        cout << endl;
    }

    void putCircle()
    {
        cout << "X-axis: " << x << "\t\t"
             << "Y-axis: " << y << "\t\t"
             << "Radius: " << radius << endl;

        cout << endl;
    }

    float getArea() const
    {
        float area;
        area = Circle::PI * (radius * radius);
        return area;
    }

    int getDiameter()
    {
        int diameter;
        diameter = radius * 2;
        return diameter;
    }

    double getCircumference()
    {
        double circumference;
        circumference = 2 * Circle::PI * radius;
        return circumference;
    }

    Circle add(const Circle &obj)
    {
        Circle sum;
        sum.x = x + obj.x;
        sum.y = y + obj.y;
        sum.radius = radius + obj.radius;
        return sum;
    }

    bool isEqual(Circle o2)
    {
        if (this->x == o2.x && this->y == o2.y && this->radius == o2.radius)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    int findCircle(const Circle o2[], int size)
    {
        for (int i = 0; i < size; i++)
        {
            if (o2[i].x == this->x && o2[i].y == this->y && o2[i].radius == this->radius)
                return i;
        }
        return -1;
    }

    void update(Circle o2[], int size)
    {
        for (int i = 0; i < size; i++)
        {
            if (o2[i].x == this->x && o2[i].y == this->y)
                o2[i].radius = this->radius;
        }
    }

    void print(Circle o2[], int size)
    {
        for (int i = 0; i < size; i++)
            cout << o2[i].x << "    " << o2[i].y << "       " << o2[i].radius << endl;
    }
};

const double Circle::PI = 3.1416;

int main()
{
    system("cls");

    Circle obj1(1, 2, 9.5);

    Circle o1[2] = {Circle(1, 3, 3.3), Circle(1, 2, 5.8)};

    Circle o2[2] = {Circle(1, 2, 5.5), Circle(1, 2, 9.5)};
    //                  index 0      ,      index 1

    cout << "Find if x, y and radius are equal then return index else return -1"<< endl;
    cout << obj1.findCircle(o2, 2) << endl; // obj1 k x, y, radius ko compare krna array o2 k dono index k x, y, radius se

    cout << endl;

    cout << "Finding if x and y of LHS and RHS are equal then update the RHS radius to the LHS" << endl;
    obj1.update(o1, 2);  // obj1 k x, y ko o1 k index 1 or 2 k x, se compare krna 
    obj1.print(o1, 2);

   

    
    // obj1.getCircle();
    // obj1.putCircle();

    // obj2.getCircle();
    // obj2.putCircle();

    // obj1.isEqual(obj2);

    // cout << endl;

    // obj1.update(o2, 2);
    // obj1.print(o2, 2);

    return 0;
}