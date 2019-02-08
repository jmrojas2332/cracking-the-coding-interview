#include "arraylist.h"
#include <iostream>

int main()
{
    ArrayList<int> arr(1);
    arr.append(1);
    arr.append(2);
    arr.append(3);
    arr.append(4);
    std::cout << "Popping..." << arr.pop() << "\n";

    std::cout << arr << "\n";

    ArrayList<int> arr2 = std::move(arr);
    std::cout << arr2 << "\n";

    arr2[1] = 1;
    std::cout << arr2 << "\n";
    std::cout << arr << "\n";
    std::cout << "Popping..." << arr2.pop() << "\n";
    std::cout << "Popping..." << arr2.pop() << "\n";
    std::cout << "Popping..." << arr2.pop() << "\n";
    std::cout << arr2;

    return 0;
}
