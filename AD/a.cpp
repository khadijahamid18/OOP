#include <iostream>
#include <string>

using namespace std;

class Product
{
private:
    string name;
    double price;
    int quantity;
    int id;
    static int count;

public:
    Product() : name(""), price(0.0), quantity(0), id(0) {}
    Product(int id, string name, double price, int quantity) : id(id), name(name), price(price), quantity(quantity) { count++; }
    ~Product() {}
    string getName() { return name; }
    void setName(string name) { this->name = name; }
    double getPrice() { return price; }
    void setPrice(double price) { this->price = price; }
    int getQuantity() { return quantity; }
    void setQuantity(int quantity) { this->quantity = quantity; }
    int getId() { return id; }
    static int getCount() { return count; }
    bool operator<(Product &prod) { return price < prod.getPrice(); }
    bool operator>(Product &prod) { return price > prod.getPrice(); }
    void print() { cout << "Id: " << id << ", Name: " << name << ", Price: " << price << ", Quantity: " << quantity << endl; }
};

int Product::count = 0;

class Shop
{
private:
    Product *products;
    int totalProducts;
    int currentProducts;

public:
    Shop(Product *products, int totalProducts, int currentProducts) : totalProducts(totalProducts), currentProducts(currentProducts)
    {
        this->products = new Product[totalProducts];
        for (int i = 0; i < currentProducts; i++)
            this->products[i] = products[i];
    }
    Shop(const Shop &shop)
    {
        totalProducts = shop.totalProducts;
        currentProducts = shop.currentProducts;
        products = new Product[totalProducts];
        for (int i = 0; i < currentProducts; i++)
            products[i] = shop.products[i];
    }
    ~Shop()
    {
        delete[] products;
    }
    void addProduct(int id, string name, double price, int quantity)
    {
        if (currentProducts == totalProducts)
        {
            cout << "Shop is full!" << endl;
            return;
        }
        Product newProd(id, name, price, quantity);
        products[currentProducts++] = newProd;
    }
    bool removeProduct(int id)
    {
        bool prodRemoved = false;
        for (int i = 0; i < currentProducts; i++)
        {
            if (products[i].getId() == id)
            {
                for (int j = i; j < currentProducts - 1; j++)
                    products[j] = products[j + 1];
                currentProducts--;
                prodRemoved = true;
                break;
            }
        }
        return prodRemoved;
    }
    void displayProducts()
    {
        for (int i = 0; i < currentProducts; i++)
            products[i].print();
    }
    bool updatePrice(int id, float price)
    {
        for (int i = 0; i < currentProducts; i++)
        {
            if (products[i].getId() == id)
            {
                products[i].setPrice(price);
                return true;
            }
        }
        return false;
    }
    bool updateQuantity(int id, int quantity)
    {
        bool quantityUpdated = false;
        for (int i = 0; i < currentProducts; i++)
        {
            if (products[i].getId() == id)
            {
                products[i].setQuantity(quantity);
                quantityUpdated = true;
                break;
            }
        }
        return quantityUpdated;
    }
    Product *getProducts() { return products; }
    int getTotalProducts() { return totalProducts; }
    int getCurrentProducts() { return currentProducts; }
};

class Cart
{
private:
    Product *products;
    int size;
    int currentSize;
    double totalCost;

public:
    Cart(int size) : size(size), currentSize(0), totalCost(0.0)
    {
        products = new Product[size];
        for (int i = 0; i < size; i++)
            products[i] = Product();
    }
    Cart(const Cart &cart) : size(cart.size), currentSize(cart.currentSize), totalCost(cart.totalCost)
    {
        products = new Product[size];
        for (int i = 0; i < size; i++)
            products[i] = cart.products[i];
    }
    ~Cart()
    {
        delete[] products;
    }
    bool addProduct(Shop *shop, int id, int quantity)
    {
        if (currentSize == size)
        {
            cout << "Cart is full!" << endl;
            return false;
        }
        for (int i = 0; i < shop->getCurrentProducts(); i++)
        {
            if (shop->getProducts()[i].getId() == id)
            {
                if (quantity <= shop->getProducts()[i].getQuantity())
                {
                    Product newProd = shop->getProducts()[i];
                    newProd.setQuantity(quantity);
                    products[currentSize++] = newProd;
                    totalCost += newProd.getPrice() * quantity;
                    shop->updateQuantity(id, shop->getProducts()[i].getQuantity() - quantity);
                    return true;
                }
                else
                {
                    cout << "Not enough quantity available in the shop!" << endl;
                    return false;
                }
            }
        }
        cout << "Product with id: " << id << " not found in the shop!" << endl;
        return false;
    }
    bool removeProduct(Shop *shop, int id)
    {
        bool prodRemoved = false;
        for (int i = 0; i < currentSize; i++)
        {
            if (products[i].getId() == id)
            {
                while (i < currentSize - 1)
                {
                    products[i] = products[i + 1];
                    i++;
                }
                currentSize--;
                totalCost -= products[i].getPrice() * products[i].getQuantity();
                shop->updateQuantity(id, shop->getProducts()[i].getQuantity() + products[i].getQuantity());
                prodRemoved = true;
                break;
            }
        }
        return prodRemoved;
    }
    bool updateQuantity(Shop *shop, int id, int quantity)
    {
        for (int i = 0; i < currentSize; i++)
        {
            if (products[i].getId() == id)
            {
                if (quantity <= shop->getProducts()[i].getQuantity())
                {
                    totalCost -= products[i].getPrice() * products[i].getQuantity();
                    totalCost += products[i].getPrice() * quantity;
                    products[i].setQuantity(quantity);
                    shop->updateQuantity(id, shop->getProducts()[i].getQuantity() + products[i].getQuantity() - quantity);
                    return true;
                }
                else
                {
                    cout << "Not enough quantity available in the shop!" << endl;
                    return false;
                }
            }
        }
        cout << "Product with id: " << id << " not found in the cart!" << endl;
        return false;
    }
    double getTotalCost() { return totalCost; }
    void displayCart()
    {
        for (int i = 0; i < currentSize; i++)
            products[i].print();
        cout << "Total cost: " << totalCost << endl;
    }
    void clearCart(Shop *shop)
    {
        for (int i = 0; i < currentSize; i++)
            shop->updateQuantity(products[i].getId(), shop->getProducts()[i].getQuantity() + products[i].getQuantity());
        currentSize = 0;
        totalCost = 0.0;
    }
};

int main()
{
    Product p1(1, "Laptop", 800.00, 10);
    Product p2(2, "Phone", 500.00, 5);
    Product p3(3, "Monitor", 200.00, 8);
    Product p4(4, "Tablet", 350.00, 2);
    Product p5(5, "Keyboard", 50.00, 3);

    Product products[] = {p1, p2, p3, p4, p5};
    Shop shop(products, 5, 5);
    shop.addProduct(6, "Mouse", 20.00, 15);
    shop.addProduct(7, "Headphones", 50.00, 10);
    shop.displayProducts();

    Cart cart(5);
    cart.addProduct(&shop, 7, 2);
    cart.addProduct(&shop, 2, 3);
    cart.addProduct(&shop, 1, 1);
    cart.displayCart();
    cart.updateQuantity(&shop, 7, 1);
    cart.displayCart();

    cart.addProduct(&shop, 5, 2);
    cart.addProduct(&shop, 4, 1);
    cart.displayCart();

    cart.removeProduct(&shop, 7);
    cart.displayCart();

    cart.clearCart(&shop);
    cart.displayCart();

    return 0;
}