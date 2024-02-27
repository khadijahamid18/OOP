#include <iostream>
#include <string>
#include <iomanip>
#include "Product.h"
#include "Shop.h"
using namespace std;

class Cart {
private:
    Product* products;
    int size;
    int currentSize;
    double totalCost;
public:
    Cart(int size) {
        this->size = size;
        this->currentSize = 0;
        this->totalCost = 0.0;
        this->products = new Product[size];
        for (int i = 0; i < size; i++) {
            products[i] = Product();
        }
    }

    Cart(const Cart& cart) {
        this->size = cart.size;
        this->currentSize = cart.currentSize;
        this->totalCost = cart.totalCost;
        this->products = new Product[cart.size];
        for (int i = 0; i < cart.size; i++) {
            this->products[i] = cart.products[i];
        }
    }

    ~Cart() {
        delete[] products;
    }

    bool addProduct(Shop* shop, int id, int quantity) {
        Product* product = shop->getProductById(id);
        if (product == nullptr) {
            return false;
        }
        int availableQuantity = product->getQuantity();
        if (quantity > availableQuantity) {
            return false;
        }
        if (currentSize == size) {
            return false;
        }
        for (int i = 0; i < currentSize; i++) {
            if (products[i].getId() == id) {
                return false;
            }
        }
        Product newProduct(product->getId(), product->getName(), product->getPrice(), quantity);
        products[currentSize] = newProduct;
        currentSize++;
        double cost = newProduct.getPrice() * quantity;
        totalCost += cost;
        int newQuantity = availableQuantity - quantity;
        product->setQuantity(newQuantity);
        return true;
    }

    bool removeProduct(Shop* shop, int id) {
        int index = -1;
        for (int i = 0; i < currentSize; i++) {
            if (products[i].getId() == id) {
                index = i;
                break;
            }
        }
        if (index == -1) {
            return false;
        }
        Product product = products[index];
        int quantity = product.getQuantity();
        shop->updateQuantityById(id, quantity);
        for (int i = index; i < currentSize - 1; i++) {
            products[i] = products[i + 1];
        }
        products[currentSize - 1] = Product();
        currentSize--;
        double cost = product.getPrice() * product.getQuantity();
        totalCost -= cost;
        return true;
    }

    bool updateQuantity(Shop* shop, int id, int quantity) {
        int index = -1;
        for (int i = 0; i < currentSize; i++) {
            if (products[i].getId() == id) {
                index = i;
                break;
            }
        }
        if (index == -1) {
            return false;
        }
        Product product = products[index];
        int availableQuantity = shop->getProductById(id)->getQuantity();
        if (quantity > availableQuantity) {
            return false;
        }
        double oldCost = product.getPrice() * product.getQuantity();
        double newCost = product.getPrice() * quantity;
        double costDifference = newCost - oldCost;
        totalCost += costDifference;
        int quantityDifference = quantity - product.getQuantity();
        shop->update
