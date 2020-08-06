#include <iostream>

#include "arraylist.h"
#include "hashtable.h"
#include "stringbuilder.h"


int main()
{
    // HashTable<std::string, int> tab;
    // tab.insert("Hello", 1);
    // tab.insert("World", -1);
    // tab.insert("World", -1);
    // tab.insert("World", 2);
    // tab.insert("A", 1);
    // tab.insert("B", -1);
    // tab.insert("C", -3);
    // std::cout << tab << "\n";

    // HashTable<std::string, int> tab2;
    // tab2 = std::move(tab);
    // std::cout << tab2 << "\n";
    // std::cout << tab << "\n";

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

    StringBuilder sb;
    sb.append("a");
    sb.append("ab");
    sb.append("abc");
    sb.append("abcd");
    std::cout << "Array1: " << sb << "\n";
    std::cout << "Popping..." << sb.pop() << "\n";
    std::cout << "Array1: " << sb << "\n";
    
    StringBuilder sb2 = std::move(sb);
    std::cout << "Moved Array1 to Array2" << "\n";
    std::cout << "Array1: " << sb << "\n";
    std::cout << "Array2: " << sb2 << "\n";
    
    std::cout << "Popping..." << sb2.pop() << "\n";
    std::cout << "Array2: " << sb2 << "\n";
    
    sb = std::move(sb2);
    std::cout << "Move Assignment to Array1 from Array2" << "\n";
    std::cout << "Array1: " << sb << "\n";
    std::cout << "Array2: " << sb2 << "\n";

    return 0;
}
