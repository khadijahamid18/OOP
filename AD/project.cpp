#include <iostream>
using namespace std;

class Product
{
    string name;
    double price;
    int quantity;
    int id;
    static int count;

public:
    // Member Fuction

    // Default Constructor
    Product()
    {
        name = "";
        price = 0;
        quantity = 0.0;
        id = 0;
    }

    // Parameterized Constructor
    Product(int id, string name, double price, int quantity)
    {
        this->name = name;
        this->price = price;
        this->quantity = quantity;
        this->id = id;
    }

    // Destructor
    ~Product()
    {
    }

    void setName(string name)
    {
        this->name = name;
    }

    string getName()
    {
        return name;
    }

    void setPrice(double price)
    {
        this->price = price;
    }

    double getPrice()
    {
        return price;
    }

    void setQuantity(int quantity)
    {
        this->quantity = quantity;
    }

    int getQuantity()
    {
        return quantity;
    }

    int getId()
    {
        return id;
    }

    static int getCount()
    {
        return count;
    }

    bool operator<(const Product &obj)
    {
        // if (this->price < obj.price)
        // {
        //     return true;
        // }
        // else
        //     return false;
        return (this->price < obj.price);
    }

    bool operator>(const Product &obj)
    {
        // if (this->price > obj.price)
        // {
        //     return true;
        // }
        return (this->price > obj.price);
    }

    void print()
    {
        cout << "Id: " << getId() << endl;
        cout << "Name: " << getName() << endl;
        cout << "Price: " << getPrice() << endl;
        cout << "Quantity: " << getQuantity() << endl
             << endl;
    }
};

int Product::count = 0;

class Shop
{
    Product *products;
    int totalProducts;
    int currentProducts;

public:
    // Member Function

    Shop(Product products[], int size, int totalProd)
    {
        this->totalProducts = totalProd;
        this->currentProducts = size;
        this->products = new Product[totalProducts];

        for (int i = 0; i < size; i++)
        {
            this->products[i] = products[i];
        }
    }

    Shop(const Shop &obj)
    {
        this->totalProducts = obj.totalProducts;
        this->currentProducts = obj.currentProducts;
        this->products = new Product[totalProducts];

        for (int i = 0; i < currentProducts; i++)
        {
            this->products[i] = obj.products[i];
        }
    }

    ~Shop()
    {
        delete[] products;
    }

    void addProduct(int id, string name, double price, int quantity)
    {
        if (currentProducts < totalProducts)
        {
            Product obj(id, name, price, quantity);
            products[currentProducts] = obj;
            currentProducts++;
        }
        else
            cout << "Capacity is full. Can't add a new product!\n";
    }

    bool removeProduct(int id)
    {
        bool flag = false;
        if (currentProducts > 0)
        {
            for (int i = 0; i < currentProducts; i++)
            {
                if (products[i].getId() == id)
                {
                    flag = true;
                    // remove the object
                    while (i < currentProducts)
                    {
                        products[i] = products[i + 1];
                        i++;
                    }
                    // decrease the currentProduct
                    currentProducts--;
                }
            }
        }
        return flag;
    }

    void displayProducts() const
    {
        for (int i = 0; i < currentProducts; i++) // currentProduct is the size of the array
        {
            products[i].print();
        }
    }

    bool updatePrice(int id, float price)
    {
        bool flag = false;
        for (int i = 0; i < currentProducts; i++)
        {
            if (products[i].getId() == id)
            {
                products[i].setPrice(price);
                flag = true;
            }
        }
        return flag;
    }

    bool updateQuantity(int id, int quantity)
    {
        bool flag = false;
        for (int i = 0; i < currentProducts; i++)
        {
            if (products[i].getId() == id)
            {
                products[i].setQuantity(quantity);
                flag = true;
            }
        }
        return flag;
    }

    Product *getProducts()
    {
        return products;
    }

    int getTotalProducts()
    {
        return totalProducts;
    }

    int getCurrentProducts()
    {
        return currentProducts;
    }
};

class Cart
{
    Product *products;
    int size;
    int currentSize;
    double totalCost;

public:
    // Member Function

    Cart(int size)
    {
        this->products = new Product[size];
        this->totalCost = 0;
        this->currentSize = 0;
    }

    Cart(const Cart &obj)
    {
        this->currentSize = obj.currentSize;
        this->totalCost = obj.totalCost;
        this->size = obj.size;
        this->products = new Product[size];

        for (int i = 0; i < currentSize; i++)
        {
            this->products[i] = obj.products[i];
        }
    }

    ~Cart()
    {
        delete[] products;
    }

    //      adds a product to the cart only if that product is
    // present is that specific shop and updates the total cost; returns true if the product was successfully
    // added, false otherwise

    bool addProduct(Shop *shop, int id, int quantity)
    {
        Product *product;
        if (currentSize == size && product->getId() > size)
        {
            return false;
        }
        for (int i = 0; i < currentSize; i++)
        {
            if (products[i].getId() == id)
            {
                return false;
            }
        }

        Product add(product->getId(), product->getName(), product->getPrice(), product->getQuantity());
        products[currentSize] = add;
        currentSize++;

        double cost = quantity * product->getPrice();
        totalCost += cost;
        quantity--;
        return true;
    }
};

int main()
{
    system("cls");
    
    Product arr[] = {Product(1, "Food", 12.5, 5), Product(2, "Toy", 13.5, 5), Product(3, "cloth", 120, 5)};

    Shop s1(arr, 3, 10);
    s1.addProduct(5, "fruit", 90, 20);

    s1.removeProduct(2);

    // s1.updatePrice(3, 13);

    // s1.updateQuantity(1, 15);

    Shop shop(arr, 3, 5);

    Cart c1(5);
    c1.addProduct(&shop, 7, 2);
    c1.addProduct(&shop, 2, 3);


    s1.displayProducts();

    return 0;
}