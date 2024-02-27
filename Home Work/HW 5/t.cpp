#include <iostream>
#include "IntegerSet.h"   // Assuming IntegerSet class is defined in IntegerSet.h

int main() {
    int setSize = 10;   // Size of the IntegerSet
    IntegerSet set1(setSize);   // Create set1 with given size
    
    // Insert elements into set1
    set1.insertElement(1);
    set1.insertElement(3);
    set1.insertElement(4);
    set1.insertElement(7);
    set1.insertElement(9);

    std::cout << "Set1: " << set1 << std::endl;   // Print set1

    // Create set2 as a copy of set1
    IntegerSet set2 = set1;

    // Delete elements from set2
    set2.deleteElement(3);
    set2.deleteElement(7);

    std::cout << "Set2: " << set2 << std::endl;   // Print set2

    // Create set3 as the union of set1 and set2
    IntegerSet set3 = set1.unionOfSets(set2);

    std::cout << "Set3 (Union of Set1 and Set2): " << set3 << std::endl;   // Print set3

    // Create set4 as the intersection of set1 and set2
    IntegerSet set4 = set1.intersectionOfSets(set2);

    std::cout << "Set4 (Intersection of Set1 and Set2): " << set4 << std::endl;   // Print set4

    // Check if an element exists in set1
    int key = 4;
    if (set1.findElement(key)) {
        std::cout << key << " is present in Set1." << std::endl;
    } else {
        std::cout << key << " is not present in Set1." << std::endl;
    }

    return 0;
}
