#include <iostream>
using namespace std;

class Item
{
    int id;
    string name;
    int quantity;
    float cost;

public:
    // Mutators and Accessors

    void setId(int id)
    {
        if (id > 0)
        {
            this->id = id;
        }
        else
        {
            this->id = 0;
        }
    }
    int getId()
    {
        return this->id;
    }

    void setName(string name)
    {
        this->name = name;
    }
    string getName()
    {
        return this->name;
    }

    void setQuantity(int quantity)
    {
        if (quantity > 0)
        {
            this->quantity = quantity;
        }
        else
        {
            this->quantity = 0;
        }
    }
    int getquantity()
    {
        return this->quantity;
    }

    void setCost(float cost) 
    {
        if (cost > 0)
        {
            this->cost = cost;
        }
        else
        {
            this->cost = 0;
        }
    }
    float getcost()
    {
        return this->cost;
    }

    // Constructors and Destructors

    Item(int number, string name, int quantity, float cost)
    {
        cout << "Parameterized Constructors" << endl;
        setId(number);
        setName(name);
        setQuantity(quantity);
        setCost(cost);
    }

    Item(int number, string name, int quantity)
    {
        setId(number);
        setName(name);
        setQuantity(quantity);
        this->cost = 0;
    }

    Item(int number, string name, float cost)
    {
        setId(number);
        setName(name);
        setCost(cost);
        this->quantity = 0;
    }

    Item(const Item &obj)
    {
        cout << "Copy Constructors" << endl;
        this->id = obj.id;
        this->name = obj.name;
        this->quantity = obj.quantity;
        this->cost = obj.cost;
    }

    ~Item()
    {
        cout << "Destructor Executed" << endl;
    }

    // Non Static Member Functions

    void setItem(int number, string name, int quantity, float cost)
    {
        setId(number);
        setName(name);
        setQuantity(quantity);
        setCost(cost);
    }

    void getItem()
    {
        cout << "Please enter the item's ID: ";
        cin >> this->id;
        setId(id);

        cout << "Please enter the item's name: ";
        cin >> this->name;
        setName(name);

        cout << "Please enter the item's quantity: ";
        cin >> this->quantity;
        setQuantity(quantity);

        cout << "Please enter the item's cost: ";
        cin >> this->cost;
        setCost(cost);

        cout << endl;
    }

    void putItem()
    {
        cout << "ID: " << id << "\t\t"
             << "Name: " << name << "\t\t"
             << "Quantity: " << quantity << "\t\t"
             << "Cost: " << cost << endl;

        cout << endl;
    }

    float getTotalCost()
    {
        if (quantity >= 1)
        {
            return quantity * cost;
        }
        else
        {
            return 0;
        }
    }

    bool isEqual(const Item &obj)
    {
        if (this->id == obj.id && this->name == obj.name && this->quantity == obj.quantity && this->cost == obj.cost)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void updateName(Item obj[], int size)
    {
        for (int i = 0; i < size; i++)
        {
            if (obj[i].id == this->id)
            {
                obj[i].name = this->name;
            }
        }
    }

    Item getMinimumCostItem(Item arr[], int size) 
    {
        int min = 0;
        for (int i = 1; i <= size; i++)
        {
            if (arr[i].getcost() < arr[min].getcost())  // getcost() = cost
            {
                min = i;
            }
        }
        return arr[min]; 
    }

    void getAveragePrice(Item obj[], int size)
    {
        float sum = 0;
        float average = 0;
        for (int i = 0; i < size; i++)
        {
            sum = sum + obj[i].cost;
        }
        average = sum / size;

        this->cost = average;
    }
};

int main()
{
    system("cls");

    Item o2(13, "noodles", 2, 12.5);
    Item obj[3] = {Item(13, "noodles", 2, 12.5), Item(10, "Biscuit", 5, 13.8), Item(15, "chocolate", 6, 18.7)};

    Item o1(obj[1]);

    o1.putItem();

    obj[0].getAveragePrice(obj, 3);

    cout << endl;

    obj[0].getMinimumCostItem(obj, 3);


    cout << "Average: " <<  obj[0].getcost() << endl;

    cout << endl;

    Item o3(13, "bag", 5);
    o3.updateName(obj, 3);
    o2.putItem();
    obj[0].putItem();

    Item min(obj[1]);
    min = obj[0].getMinimumCostItem(obj, 3);
    min.putItem(); 



    return 0;
}