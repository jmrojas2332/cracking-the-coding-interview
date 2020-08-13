// Cracking the Coding Interview Question 1.4 Palindrome Permutation
//
// Given a string, write a function to check if it is a permutation of a
// palindrome. A palindrome is a word or phrase that is the same forwards as
// backwards. A permutation is a rearrangement of letters. The palindrome does not
// need to be limited to just dictionary words.

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

// Time Complexity: O(n) where n is the length of the string
// In a palindrome, each character has a matching character, w/ the possible
// exception of the middle character. Therefore, we know that in order to be
// a permutation of a palindrome, there can be at most one charactor with an
// odd-numbered count. Run through string, keeping track of an oddCount
//
// Space Complexity: O(n) where n is length of the string.
// At most n characters will be stored in unordered set.
// Note: If given a character set (i.e., ASCII, Unicode) the space complexity
// could be O(min(c, m)) where c is the size of the alphabet
bool isPalindromePermutation(const std::string& str)
{
    std::unordered_map<char, unsigned int> charCounts;
    unsigned int oddCount = 0;

    for (const char &c : str)
    {
        if (charCounts.find(c) != charCounts.end())
        {
            charCounts[c] += 1;
            
            if (charCounts[c] % 2 == 1)
            {
                ++oddCount;
            }
            else
            {
                --oddCount;
            }            
        }
        else
        {
            charCounts[c] = 1;
            ++oddCount;
        }
    }

    return oddCount <= 1;
}

int main()
{
    std::vector<std::string> palindromePermutations;
    std::vector<std::string> notpalindromePermutations;
    palindromePermutations.push_back("aba");
    palindromePermutations.push_back("aab");
    palindromePermutations.push_back("abba");
    palindromePermutations.push_back("bbaa");
    palindromePermutations.push_back(" ");   // edge case: space
    palindromePermutations.push_back("  ");  // edge case: two spaces
    notpalindromePermutations.push_back("abc");
    notpalindromePermutations.push_back("abbc");

    for (const auto &str : palindromePermutations)
    {
        bool result = isPalindromePermutation(str);
        if (result == true)
        {
            std::cout << "'" << str << "' is a palindrome permutation.\n";
        }
        else
        {
            std::cout << "Incorrect result of not palindrom permutation for: " + str  << std::endl;
        }        
    }

    for (const auto &str : notpalindromePermutations)
    {
        bool result = isPalindromePermutation(str);
        if (result == false)
        {
            std::cout << "'" << str << "' is not a palindrome permutation.\n";
        }
        else
        {
            std::cout << "Incorrect result of palindrome permutation for: " + str  << std::endl;
        }
    }

    return 0;
}
