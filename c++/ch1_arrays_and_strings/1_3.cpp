// Cracking the Coding Interview Question 1.3 URLify
//
// Write a method to replace all spaces in a string with '%20'. You may assume
// that the string has sufficient space at the end to hold the additional
// characters, and that you are given the "true" length of the string.

#include <iostream>
#include <tuple>
#include <vector>

// Time Complexity: 
//
// Space Complexity: 
void urlify(std::string &str, unsigned int length)
{
    unsigned int indexItr = str.length();
    for (int i = length - 1; i >= 0; --i)
    {
        if (str[i] == ' ')
        {
            str[--indexItr] = '0';
            str[--indexItr] = '2';
            str[--indexItr] = '%';
        }
        else
        {
            str[--indexItr] = str[i];
        }        
    }
}

int main()
{
    std::vector<std::tuple<std::string, int, std::string>> urls;
    urls.push_back(std::make_tuple("hello world  ", 11, "hello%20world"));
    urls.push_back(std::make_tuple(
        "a longer string than the previous one            ",
        37,
        "a%20longer%20string%20than%20the%20previous%20one"));

    urls.push_back(std::make_tuple("      ", 2, "%20%20"));  // edge case: two spaces
    urls.push_back(std::make_tuple("", 0, ""));              // edge case: empty string

    for (auto &tuple : urls)
    {
        urlify(std::get<0>(tuple), std::get<1>(tuple));
        
        if (std::get<0>(tuple) == std::get<2>(tuple))
        {
            std::cout << "String succesfully urlified: " << std::get<0>(tuple) << std::endl;
        }
        else
        {
            std::cout << "String not properly encoded: " << std::get<0>(tuple) << std::endl;
        }     
    }
}