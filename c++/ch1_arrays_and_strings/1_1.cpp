// Cracking the Coding Interview Question 1.1 Is Unique
//
// Implement an algorithm to determine if a string has all unique characters. What
// if you cannot use additional data structures?

// Assumption: We do not know the size of the alphabet. In real interview we 
// should ask if there is an alphabet (alpha chars only, all ascii, etc.).
// Assume alphabet is arbitray size.

// Assumption: a and A are unique

#include <iostream>
#include <unordered_set>
#include <vector>

// Time Complexity: O(n) where n is the length of the string.
// A constant-time lookup and constant-time insertion is done for each char in
// string.
//
// Space Complexity: O(n) where n is length of the string.
// At most n characters will be stored in unordered set.
bool isUnique(const std::string &str)
{
    std::unordered_set<char> lookupTable;
    for (const char &c : str)
    {
        if (lookupTable.count(c) != 0)
        {
            return false;
        }
        else
        {
            lookupTable.insert(c);
        }        
    }

    return true;
}

// Follow-Up: What if you cannot use additional data structures?

// Time-Complexity: O(n^2) where n is the length of the string.
// Each character needs to be compared to every other character.
// 
// Space Complexity O(1)
bool isUniqueFollowUp(const std::string &str)
{
    for (unsigned int i = 0; i < str.length() - 1; ++i)
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
    std::vector<std::string> unique;
    std::vector<std::string> notUnique;
    unique.push_back("world");
    unique.push_back("123abc.?/*~");
    unique.push_back("aAbBcC"); // edge case: case-sensitivity of a letter is assumed to be unique
    unique.push_back(""); // edge case: empty string, assume it is unique
    unique.push_back("\t\n "); // edge case: tab, newline and space are unique
    notUnique.push_back("hello");
    notUnique.push_back("  ");  // edge case: two spaces are same char, not unique

    for (const std::string &str : unique)
    {
        bool result = isUnique(str);
        if (result == true)
        {
            std::cout << "'" << str << "' is unique.\n";
        }
        else
        {
            std::cout << "Incorrect result of not unique for: " + str << std::endl;
        }        
    }

    for (const auto &str : notUnique)
    {
        bool result = isUnique(str);
        if (result == false)
        {
            std::cout << "'"<< str << "' is not unique.\n";
        }
        else
        {
            std::cout <<  "Incorrect result of unique for: " + str << std::endl;
        }
    }
}