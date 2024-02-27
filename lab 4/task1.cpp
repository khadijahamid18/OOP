#include <iostream>
using namespace std;

class Car
{
// class is by default private
    int yearModel;
    string make;
    int speed;

public:

    // Parametrized Constructor(in which arguments are passed)
    Car(int model, string makes)
    {
        cout << "Parameterized Constructor..." << endl;
        model = yearModel;
        makes = make;
        speed = 0;
    }

    // Copy Constructor
    Car(const Car &obj)
    {
        cout << "Copy Constructor..." << endl;
        yearModel = obj.yearModel;
        make = obj.make;
        speed = obj.speed;
    }

    ~Car()
    {
        cout << "Destructor executed..." << endl;
    }

    // Getters and Setters

    void setYearModel(int model)
    {
        if (model >= 0)
        {
            yearModel = model;
        }
        else
        {
            yearModel = 0;
        }
    }

    int getYearModel()
    {
        return yearModel;
    }

    void setMake(string m)
    {
        make = m;
    }

    string getMake() 
    {
        return make;
    }

    void setSpeed(int s)
    {
        speed = s;
    }

    int getSpeed()
    {
        return speed;
    }

    // Member Function

    void setCar(int carsYearModel, string makes, int speed)
    {
        setYearModel(carsYearModel);
        setMake(makes);
        setSpeed(speed);
    }

    void getCar()
    {
        cout << "Enter Car's year model: " << endl;
        cin >> yearModel;

        cout << "Enter Car's maker: " << endl;
        cin >> make;

        cout << "Enter Car's speed: " << endl;
        cin >> speed;

        cout << endl;
    }

    void putCar()
    {
        // cout << "Car's Year Model: " << yearModel << endl;

        // cout << "Car's Maker name: " << make << endl;

        // cout << "Car's speed: " << speed << endl;

        cout << "Year Model: " << "\t" << "Make: " << "\t" << "Speed: " << endl;

    }

    void accelerate()
    {
        speed = speed + 5;
    }

    void brake()
    {
        speed = speed - 5;
    }

};

int main()
{
    system("cls");
    Car obj1(2021, "Suzuki Alto");
    Car obj2(2015, "Toyota Camry");
    Car obj3 = obj1;   // calls copy constructor
    Car obj4(2015, "Toyota Camry");
    Car obj5 = obj2;
    
    obj1.getCar();
    obj1.accelerate();

    obj2.getCar();
    obj3.getCar();
    obj3.brake();

    obj4.getCar();
    obj5.getCar();

    cout << "Year Model: " << "\t" << "Make: " << "\t" << "Speed: " << endl;

    cout << endl;

    obj1.putCar();
    obj2.putCar();
    obj3.putCar();
    obj4.putCar();
    obj5.putCar();


    return 0;
}