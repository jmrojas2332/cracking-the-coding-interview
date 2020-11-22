// Cracking the Coding Interview Question 1.1 Is Unique
//
// Implement an algorithm to determine if a string has all unique characters.
// Follow up: What if you cannot use additional data structures?

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
// Note: If given a character set (i.e., ASCII, Unicode) the space complexity
// could be O(min(c, m)) where c is the size of the alphabet
bool is_unique(const std::string &str)
{
    std::unordered_set<char> lookup_table;
    for (const char &c : str) {
        if (lookup_table.count(c) != 0) {
            return false;
        }

        lookup_table.insert(c);
    }

    return true;
}

// Follow-Up: What if you cannot use additional data structures?

// Time-Complexity: O(n^2) where n is the length of the string.
// Each character needs to be compared to every other character.
// 
// Space Complexity O(1)
bool is_unique_follow_up(const std::string &str)
{
    if (str.length() == 0) {
        return true;
    }

    for (unsigned int i = 0; i < str.length() - 1; ++i) {
        for (unsigned int j = i + 1; j < str.length(); ++j) {
            if (str[i] == str[j]) {
                return false;
            }
        }
    }

    return true;
}

int main()
{
    std::vector<std::string> unique;
    std::vector<std::string> not_unique;
    unique.push_back("world");
    unique.push_back("123abc.?/*~");
    unique.push_back("aAbBcC");
    unique.push_back(""); // empty string, assume it is unique
    unique.push_back("\t\n "); // tab, newline and space are different chars
    not_unique.push_back("hello");
    not_unique.push_back("  ");  // two spaces are same char

    for (const std::string &str : unique) {
        bool result = is_unique(str);
        if (result == true) {
            std::cout << "'" << str << "' is unique.\n";
        } else {
            std::cout << "Incorrect result of not unique for: " + str << std::endl;
        }
    }

    for (const auto &str : not_unique) {
        bool result = is_unique(str);
        if (result == false) {
            std::cout << "'"<< str << "' is not unique.\n";
        } else {
            std::cout <<  "Incorrect result of unique for: " + str << std::endl;
        }
    }
}
