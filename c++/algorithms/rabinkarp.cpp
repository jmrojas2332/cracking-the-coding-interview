#include <cmath>
#include <iostream>
#include <string>

constexpr int alphabetSize = 256; // Assuming our strings only contain expanded ascii
unsigned long hash(std::string s);
unsigned int code(char c);
bool isEqual(std::string a, std::string b, unsigned int startIndex);


// Search for string s inside the larger string b using the Rabin-Karp Algorithm
bool search (std::string s, std::string b)
{
    if (s.length() > b.length()) {
        return false;
    }

    unsigned long hashVal = hash(s);
    unsigned long bHashVal = hash(b.substr(0, s.length()));
    int index = 0;

    if ((hashVal == bHashVal) && isEqual(s, b, index)) {
        return true;
    }

    for (unsigned int i = 0; i < b.length() - s.length()+1; ++i) {
        bHashVal = (bHashVal - code(b[i]) * std::pow(alphabetSize, s.length() - 1)) * alphabetSize + code(b[i + s.length()]);

        if ((hashVal == bHashVal) && isEqual(s, b, i+1)) {
            return true;
        }
    }

    return  false;    
}

unsigned long hash(std::string s)
{
    long hashVal = 0;
    //int length = 0;
    for (const char &c : s) {
        hashVal = hashVal * alphabetSize + code(c);
    }

    return hashVal;
}

unsigned int code(char c)
{
    return static_cast<int>(c);
}

bool isEqual(std::string a, std::string b, unsigned int startIndex)
{
    unsigned int i = 0;
    while (i < a.length() && startIndex < b.length()) {
        if (a[i++] != b[startIndex++]) {
            return false;
        }
    }

    if (i < a.length()) {
        return false;
    }

    return true;
}

int main()
{
    std::string str1 = "hello, ";
    std::string str2 = " hello, world ";
    std::cout << str1 << " is in " << str2 << "?\n" << std::boolalpha << search(str1, str2) << '\n';
}