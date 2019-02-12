// Cracking the Coding Interview Question 1.1 Is Unique
//
// Implement an algorithm to determine if a string has all unique characters. What
// if you cannot use additional data structures?

#include <array>
#include <iostream>
#include <string>
#include <unordered_set>

bool isUnique(const std::string& str)
{
    // set stores unique elements so copying string to set removes any dups
    return std::unordered_set<char>(str.begin(), str.end()).size() == str.length();
}

bool isUniqueNoDataStructures(const std::string& str)
{
    for (unsigned int i = 0; i < str.length(); ++i)
    {
        for (unsigned int j = i + 1; j < str.length(); ++j)
        {
            if (str[i] == str[j])
            {
                return false;
            }
        }
    }

    return true;
}

int main()
{
    std::array<std::string, 7> arr {"Hello", "World", " ", "  ", "AaBb", "", "-1"};
    std::cout << "\n";
    for (const auto& val : arr)
    {
        std::string output = isUnique(val) == 1 ? "true" : "false";
        std::cout << "'" << val << "'" << " is unique: " <<  output << "\n";
    }
    std::cout << "\n";
}
