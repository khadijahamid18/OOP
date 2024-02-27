#include <iostream>
using namespace std;
#include <math.h>

class Cuboids
{
private:
    float height;
    float width;
    float depth;

public:
    // Mutators and accessors OR Getters and setters

    void setHeight(float h)
    {
        if (h > 0 && h < 35.0)
        {
            height = h;
        }
        else
        {
            height = 1;
        }
    }

    float getHeight()
    {
        return height;
    }

    void setWidth(float w)
    {
        if (w > 0 && w < 35.0)
        {
            width = w;
        }
        else
        {
            width = 1;
        }
    }

    float getWidth()
    {
        return width;
    }

    void setDepth(float d)
    {
        if (d > 0 && d < 35.0)
        {
            depth = d;
        }
        else
        {
            depth = 1;
        }
    }

    float getDepth()
    {
        return depth;
    }

    // Constructors and Destructors

    Cuboids(float cuboidHeight, float cuboidWidth, float cuboidDepth)
    {
        cout << "Constructors..." << endl;
        setHeight(cuboidHeight);
        setWidth(cuboidWidth);
        setDepth(cuboidDepth);
    }

    Cuboids(float cuboidHeight, float cuboidWidth)
    {
        setHeight(cuboidHeight);
        setWidth(cuboidWidth);
        depth = 0;   // 0 is default value
    }

    Cuboids()
    {
        cout << "Default Constructor..." << endl;
        height = 0;
        width = 0;
        depth = 0;
    }

    Cuboids(const Cuboids &obj)
    {
        cout << "Copy Constructor..." << endl;
        height = obj.height;
        width = obj.width;
        depth = obj.depth;
    }

    ~Cuboids()
    {
        cout << "Destructor Executed..." << endl;
    }

    // Member Functions

    void setCuboids(float cuboidHeight, float cuboidWidth, float cuboidDepth)
    {
        setHeight(cuboidHeight);
        setWidth(cuboidWidth);
        setDepth(cuboidDepth);
    }

    float getCuboids()
    {
        cout << "Enter the cuboid Heigth: ";
        cin >> height;
        setHeight(height);

        cout << "Enter the cuboid Width: ";
        cin >> width;
        setWidth(width);

        cout << "Enter the cuboid Depth: ";
        cin >> depth;
        setDepth(depth);

        cout << endl;
    }

    void putCuboids()
    {
        cout << "Height: " << height << "\t\t"
             << "Width: " << width << "\t\t"
             << "Depth: " << depth << endl;
    }

    float getSurfaceArea()
    {
        float result;
        result = 2 * (height * width) + 2 * (height * depth) + 2 * (width * depth);
        return result;
    }

    float getVolume()
    {
        float result;
        result = height * width * depth;
        return result;
    }

    float getSpaceDiagonal()
    {
        float result;
        result = sqrt((height * height) + (width * width) + (depth * depth));
        return result;
    }

    void putCuboidsInfo()
    {
        cout << "Surface area: " << getSurfaceArea() << "\t\t"
             << "Volume: " << getVolume() << "\t\t"
             << "Diagonal: " << getSpaceDiagonal() << endl;

             cout << endl;
    }
};

int main()
{
    system("cls");
    Cuboids obj1, obj2;
    Cuboids obj3(obj1);

    obj1.getCuboids();
    obj2.getCuboids();
    obj3.getCuboids();

    cout << endl;

    obj1.putCuboids();
    obj2.putCuboids();
    obj3.putCuboids();

    cout << endl;

    obj1.putCuboidsInfo();
    obj2.putCuboidsInfo();
    obj3.putCuboidsInfo();

    cout << endl;

    return 0;
}