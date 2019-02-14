#include <iostream>
#include "linkedlist.h"

int main()
{
    LinkedList<int> list;
    list.pushFront(1);
    list.pushFront(2);
    list.pushFront(3);
    std::cout << list << "\n";
    std::cout << "Popping: " << list.popFront() << "\n";
    std::cout << list << "\n";
    std::cout << "Popping: " << list.popFront() << "\n";
    std::cout << list << "\n";
    list.pushFront(3);
    std::cout << list << "\n";

    return 0;
}
