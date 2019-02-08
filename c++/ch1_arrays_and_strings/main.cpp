#include "arraylist.h"
#include <iostream>

int main()
{
    ArrayList<int> arr;
    arr.append(1);
    arr.append(2);

    std::cout << arr << "\n";
    arr[1] = 0;
    std::cout << arr;

    std::cout << arr;
    return 0;
}
