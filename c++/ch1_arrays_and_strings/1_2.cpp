// Cracking the Coding Interview Question 1.2 Check Permutation
//
// Given two strings, write a method to see if one is a permutation of another?

#include <iostream>
#include <vector>
#include <unordered_map>

// Time Complexity: O(m + n) where m is the length of str1 and n is the length
// of str2. 
// Store each different character of a string with a char count
// indicating how many of each different character exists in string.
// Compare those counts to the other string, returning false if any are
// different.
//
// Space Complexity: O(m) where m is the length of str1.
// The lookup table never has more than m key-value pairs, as any char of str2
// not in lookup table would tell us these are not permutations.
// Note: If given a character set (i.e., ASCII, Unicode) the spacce complexity
// could be O(min(c, m)) where c is the size of the alphabet
bool checkPermutation(const std::string &str1, const std::string &str2)
{
    // A permutation is a variation of how something is ordered. 
    // In the case of strings, a string is a permutation of another is a string
    // with the same characters, arranged in a different way.
    
    // Strings of different lengths cannot be permutations of each other.
    if (str1.length() != str2.length())
    {
        return false;
    }

    // Map each char to a char count to keep track of each char count of str1
    std::unordered_map<char, int> characterCount;
    for (const char &c : str1)
    {
        if (characterCount.count(c) == 0)
        {
            characterCount.insert(std::make_pair(c, 1));
        }
        else
        {
            characterCount[c] += 1;
        }
    }

    for (const char &c : str2)
    {
        if (characterCount.find(c) != characterCount.end())
        {
            // The strings do not have the same character count for char c.
            // Therefore, they cannot be permutations of each other.
            if (--characterCount[c] < 0)
                return false;
        }
        else
        {
            // char c was not in str1 so strings cannot be permutations
            return false;
        }        
    }

    return true;
}


int main()
{
    std::vector<std::pair<std::string, std::string>> permutations;
    std::vector<std::pair<std::string, std::string>> notPermutations;
    permutations.push_back(std::make_pair("abc", "bca"));
    permutations.push_back(std::make_pair("123", "321"));
    notPermutations.push_back(std::make_pair("abc", "bcad"));
    notPermutations.push_back(std::make_pair(" ", "  ")); // edge case; 1 space vs 2
    notPermutations.push_back(std::make_pair("", " "));   // edge case: empty vs 1 space

    for (const auto &perm : permutations)
    {
        bool result = checkPermutation(perm.first, perm.second);
        if (result == true)
        {
            std::cout << "'" << perm.second << "' is a permutation of '" << perm.first << "'.\n";
        }
        else
        {
            std::cout << "Incorrect result of not permutation for: " + perm.first + " and " + perm.second << std::endl;
        }        
    }

    for (const auto &perm : notPermutations)
    {
        bool result = checkPermutation(perm.first, perm.second);
        if (result == false)
        {
            std::cout << "'" << perm.second << "' is not a permutation of '" << perm.first << "'.\n";
        }
        else
        {
            std::cout << "Incorrect result of not permutation for: " + perm.first + " and " + perm.second << std::endl;
        }
    }
}