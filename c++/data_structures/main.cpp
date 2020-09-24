#include <iostream>

#include "arraylist.h"
#include "hashtable.h"
#include "linkedlist.h"
#include "stringbuilder.h"


int main()
{
    namespace ds =  datastructures;

    // ds::ArrayList<int> array;
    // std::cout << "ArrayList Created\n";
    // std::cout << "Size: " << array.size() << '\n';
    // std::cout << "Empty: " << std::boolalpha << array.empty() << '\n';
    // std::cout << "Capacity: " << array.capacity() << "\n\n";

    // try {
    //     std::cout << array.at(0);
    // }
    // catch (std::out_of_range &exception) {
    //     std::cout << "This is expected\n";
    //     std::cout << exception.what() << "\n\n";        
    // }

    // try {
    //     std::cout << array[0];
    // }
    // catch (std::out_of_range &exception) {
    //     std::cout << "This is expected\n";
    //     std::cout << exception.what() << "\n\n";        
    // }

    // array.pushBack(1);
    // std::cout << "Element Added\n";
    // std::cout << "Size: " << array.size() << '\n';
    // std::cout << "Empty: " << std::boolalpha << array.empty() << '\n';
    // std::cout << "Capacity: " << array.capacity() << '\n';
    // std::cout << "Element: " << array.at(0) << "\n\n";

    // array.pushBack(-1);
    // std::cout << "Element Added\n";
    // std::cout << "Size: " << array.size() << '\n';
    // std::cout << "Empty: " << std::boolalpha << array.empty() << '\n';
    // std::cout << "Capacity: " << array.capacity() << '\n';
    // std::cout << "Element: " << array[1] << "\n\n";

    // std::cout << "Changing elements at index 0 and 1\n";
    // array.at(0) = 5;
    // array[1] = -5;

    // for (const auto &item : array)
    // {
    //     std::cout << item;
    // }
    // std::cout << '\n';

    // array.popBack();

    // for (const auto &item : array)
    // {
    //     std::cout << item;
    // }
    // std::cout << "\n\n";

    // // move old array
    // ds::ArrayList<int> array2(std::move(array));
    // std::cout << "Old array moved to new array\n";
    // std::cout << "Old Array\n";
    // std::cout << "Size: " << array.size() << '\n';
    // for (const auto &item : array)
    // {
    //     std::cout << item;
    // }
    // std::cout << '\n';

    // std::cout << "New Array\n";
    // std::cout << "Size: " << array2.size() << '\n';
    // for (const auto &item : array2)
    // {
    //     std::cout << item;
    // }
    // std::cout << "\n\n";

    // // move assignment from new array back to old array
    // array = std::move(array2);
    // std::cout << "New array moved back to new array using move assignment\n";
    // std::cout << "Old Array\n";
    // std::cout << "Size: " << array.size() << '\n';
    // for (const auto &item : array)
    // {
    //     std::cout << item;
    // }
    // std::cout << '\n';

    // std::cout << "New Array\n";
    // std::cout << "Size: " << array2.size() << '\n';
    // for (const auto &item : array2)
    // {
    //     std::cout << item;
    // }
    // std::cout << '\n';
    


    // ds::StringBuilder sb;
    // sb.pushBack("Hello, ");
    // sb.pushBack("World. ");
    // sb.pushBack("I am building a string.\n");
    // std::cout << sb.toString() << "\n";

    ds::HashTable<int, int> hashTable;
    std::cout << "HashTable Created\n";
    std::cout << "Size: " << hashTable.size() << '\n';
    std::cout << "Empty: " << std::boolalpha << hashTable.empty() << '\n';
    std::cout << "Number of Buckets: " << hashTable.numBuckets() << "\n\n";
    hashTable.insert(1, 1);
    hashTable.insert(2, 1);

    std::cout << "Inserted element\n";
    std::cout << "Size: " << hashTable.size() << '\n';
    std::cout << "Empty: " << std::boolalpha << hashTable.empty() << '\n';
    std::cout << "Number of Buckets: " << hashTable.numBuckets() << "\n\n";

    std::cout << "Hashtable contains " << 1 << " " << std::boolalpha << hashTable.contains(1) << '\n';
    std::cout << "Hashtable contains " << 0 << " " << std::boolalpha << hashTable.contains(0) << '\n';

    for (auto &bucket : hashTable) {
        for (const auto &pair : bucket) {
            std:: cout << pair.first << ": " << pair.second << '\n';
        }
    }

    hashTable.erase(1);

    for (auto &bucket : hashTable) {
        for (const auto &pair : bucket) {
            std:: cout << pair.first << ": " << pair.second << '\n';
        }
    }

    // ds::LinkedList<int> list;
    // std::cout << "LinkedList Created\n";
    // std::cout << "Size: " << list.size() << '\n';
    // std::cout << "Empty: " << std::boolalpha << list.empty() << '\n';
    
    // try {
    //     std::cout << list.popFront();
    // }
    // catch (std::out_of_range &exception) {
    //     std::cout << "This is expected\n";
    //     std::cout << exception.what() << "\n\n";        
    // }

    // list.pushFront(1);
    // std::cout << "Added Element\n";
    // std::cout << "Size: " << list.size() << '\n';
    // std::cout << "Empty: " << std::boolalpha << list.empty() << '\n';
    // std::cout << "Popping Element " << list.popFront() << '\n';
    
    return 0;
}