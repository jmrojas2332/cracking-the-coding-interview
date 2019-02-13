#include "arraylist.h"
#include "hashtable.h"
#include <iostream>

int main()
{
    HashTable<std::string, int> tab;
    tab.insert("Hello", 1);
    tab.insert("World", -1);
    tab.insert("World", -1);
    tab.insert("World", 2);
    tab.insert("A", 1);
    tab.insert("B", -1);
    tab.insert("C", -3);
    std::cout << tab;

    // ArrayList<int> arr(1);
    // arr.append(1);
    // arr.append(2);
    // arr.append(3);
    // arr.append(4);
    // std::cout << "Array1: " << arr << "\n";
    // std::cout << "Popping..." << arr.pop() << "\n";
    // std::cout << "Array1: " << arr << "\n";
    //
    // ArrayList<int> arr2 = std::move(arr);
    // std::cout << "Moved Array1 to Array2" << "\n";
    // std::cout << "Array1: " << arr << "\n";
    // std::cout << "Array2: " << arr2 << "\n";
    //
    // std::cout << "Popping..." << arr2.pop() << "\n";
    // std::cout << "Array2: " << arr2 << "\n";
    //
    // arr = std::move(arr2);
    // std::cout << "Move Assignment to Array1 from Array2" << "\n";
    // std::cout << "Array1: " << arr << "\n";
    // std::cout << "Array2: " << arr2 << "\n";

    return 0;
}
