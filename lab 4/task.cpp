#include "iostream"
using namespace std;

class Car
{
public:
    /* Constructors */
    /*Car()
    {
        yearModel = 0;
        make = "name";
        speed = 0;
        cout << "Default constructor" << endl;
    }*/

    Car(int year, string name)
    {
        setYearModel(year);
        make = name;
        speed = 0;
        cout << "Partametrized Constructor..." << endl;
    }

    Car(Car &objTemp)
    {
        yearModel = objTemp.yearModel;
        make = objTemp.make;
        speed = objTemp.speed;

        cout << "Copy Constructor..." << endl;
    }

    /* Destructor */

    ~Car()
    {
        cout << "Dectructor executed..." << endl;
    }

    /* Acessor GET functions */

    int getYearModel()
    {
        return yearModel;
    }

    string getMake()
    {
        return make;
    }

    int getSpeed()
    {
        return speed;
    }

    /*  Acessor SET functions */

    void setYearModel(int year)
    {
        if (year > 0)
            yearModel = year;
        else
            yearModel = 0;
    }

    void setMake(string name)
    {
        make = name;
    }

    void setSpeed(int spd)
    {
        if (spd > 0)
            speed = spd;
        else
            speed = 0;
    }

    /*  Member functions */

    void setCar(int yearModel, string name, int speed)
    {
        setYearModel(yearModel);
        setMake(name);
        setSpeed(speed);
    }

    void getCar()
    {

        cout << "Enter the Model of car: ";
        cin >> yearModel;
        setYearModel(yearModel);

        cout << "Enter the make of car: ";
        cin >> make;
        setMake(make);

        cout << "Enter the Speed of car: ";
        cin >> speed;
        setSpeed(speed);
    }

    void putCar()
    {

        cout << yearModel << "\t\t";
        cout << make << "\t\t";
        cout << speed << endl;
    }

    void accelerate()
    {
        speed = speed + 5;
    }

    void brake()
    {
        speed = speed - 5;
    }

private:
    int yearModel;
    string make;
    int speed;
};

int main()
{
    Car obj1(2021, "Suzuki");
    obj1.setSpeed(40);

    Car obj2 = obj1;

    obj2.putCar();

    obj2.getCar();

    Car obj3(2021, "Suzuki");
    obj3.setYearModel(2011);
    obj3.setMake("Honda");
    obj3.setSpeed(80);

    Car obj4(2021, "Suzuki");
    obj4.setCar(2012, "Toyta", 55);
    obj4.accelerate();

    Car obj5(2021, "Suzuki");
    obj5.setCar(2018, "Diahatsu Boon", 60);
    obj5.brake();

    cout << "\n\n\n";
    cout << "Year model"
         << "\t\tMake"
         << "\t\tSpeed\n\n";
    obj1.putCar();
    obj2.putCar();
    obj3.putCar();
    obj4.putCar();
    obj5.putCar();

    return 0;
}