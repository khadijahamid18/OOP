#include <iostream>
using namespace std;

class Ship
{
protected:    
    string name;
    string year;

public:
    Ship(string name, string year)
    {
        this->name = name;
        this->year = year;
    }

    void setName(string name)
    {
        this->name = name;
    }

    string getName()
    {
        return name;
    }

    void setYear(string year)
    {
        this->year = year;
    }

    string getYear()
    {
        return year;
    }

    virtual void print()
    {
        cout << "Name: " << name << endl;
        cout << "Year: " << year << endl;
    }
};

class CruiseShip : public Ship
{
    int MaxNumOfPassengers;

public:
    CruiseShip(string name, string year, int passengers) : Ship(name, year) 
    {
        this->MaxNumOfPassengers = passengers;
    }

    void setPassengers(int passengers)
    {
        this->MaxNumOfPassengers = passengers;
    }

    int getPassengers()
    {
        return MaxNumOfPassengers;
    }

    void print()
    {
        Ship::print();
        cout << "Maximum Number of passengers: " << MaxNumOfPassengers << endl;
    }
};

class CargoShip : public Ship
{
    int cargoCapacity;

 public:

    CargoShip(string name, string year, int capacity ) : Ship(name, year) 
    {
        this->cargoCapacity = capacity;
    }   

    void setCapacity(int capacity)
    {
        this->cargoCapacity = capacity;
    }

    int getCapacity()
    {
        return cargoCapacity;
    }

    void print()
    {
        cout << "Name: " << name << endl;
        cout << "Cargo Capacity: " << cargoCapacity << endl;
    }
};

class BattleShip : public Ship
{
    int totalNumOfMissiles;

 public:

    BattleShip(string name, string year, int missiles ) : Ship(name, year) 
    {
        this->totalNumOfMissiles = missiles;
    }

    void setMissiles(int missiles)
    {
        this->totalNumOfMissiles = missiles;
    }

    int getMissiles()
    {
        return totalNumOfMissiles;
    }

    void print()
    {
        cout << "Name: " << name << endl;
        cout << "Missiles capacity: " << totalNumOfMissiles << endl;
    }
};


int main()
{
    system("cls");
    Ship* ships[4];
    ships[0] = new Ship("Ship 1", "2000");
    ships[1] = new CruiseShip("Cruise Ship 1", "2005", 1000);
    ships[2] = new CargoShip("Cargo Ship 1", "2010", 5000);
    ships[3] = new BattleShip("Battle Ship 1", "2015", 50);

    for (int i = 0; i < 4; i++) {
        ships[i]->print();
        cout << endl;
    }

    for (int i = 0; i < 4; i++) {
        delete ships[i];
    }

    return 0;
}