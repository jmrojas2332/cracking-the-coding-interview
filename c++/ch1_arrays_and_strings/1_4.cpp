// Cracking the Coding Interview Question 1.4 Palindrome Permutation
//
// Given a string, write a function to check if it is a permutation of a
// palindrome. A palindrome is a word or phrase that is the same forwards as
// backwards. A permutation is a rearrangement of letters. The palindrome does not
// need to be limited to just dictionary words.

#include <array>
#include <iostream>
#include <string>
#include <unordered_map>

bool isPalindromePermutation(const std::string& str)
{
    std::unordered_map<char, int> charCount;
    int oddCount = 0;  // num of chars in charCount with an odd amount for count

    for (const auto& val : str)
    {
        if (charCount.find(val) == charCount.end())
        {
            ++oddCount;
            charCount[val] = 1;
        }
        else
        {
            ++charCount[val];
            oddCount += charCount[val] % 2 == 1 ? 1 : -1;  // add 1 for odd, -1 for even
        }
    }

    return oddCount <= 1;  // if palindrome cannot have more than 1 char with odd count
}

int main()
{
    std::array<std::string, 5> test_cases {"aba", "aab", "abbc", "", " "};

    for (const auto& val : test_cases)
    {
        std::string output = isPalindromePermutation(val) == 1 ? "true" : "false";
        std::cout << "'" << val << "'" << " is a palindrome permutaion: " << output << "\n";
    }

    std::cout << "\n";

    return 0;
}
