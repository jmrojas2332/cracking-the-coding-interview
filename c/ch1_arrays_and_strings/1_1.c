/* Cracking the Coding Interview Question 1.1 Is Unique

   Implement an algorithm to determine if a string has all unique characters.
   Follow up: What if you cannot use additional data structures?

   Assumption: We do not know the size of the alphabet. In real interview we
   should ask if there is an alphabet (alpha chars only, all ascii, etc.).
   Assume alphabet is arbitray size.

   Assumption: a and A are unique
*/

#include <stdbool.h>
#include <stdio.h>

/*Assumption: using ASCII character set*/
#define CHARACTER_SET_SIZE 256


/* Time Complexity: O(n) where n is the length of the string.
   A constant-time lookup and constant-time insertion is done for each char in
   string.

   Space Complexity: O(c) where c is the size of the alphabet
*/
bool is_unique(const char *str)
{
    bool lookup_table[CHARACTER_SET_SIZE] = {0};
    while(*str) {
        if (lookup_table[(int)*str]) {
            return false;
        }

        lookup_table[(int)*str] = true;
        ++str;
    }

    return true;
}

/* Follow-Up: What if you cannot use additional data structures?

   Time-Complexity: O(n^2) where n is the length of the string.
   Each character needs to be compared to every other character.

   Space Complexity O(1)
*/
bool is_unique_follow_up(const char *str)
{
    const char *runner;
    while (*str) {
        runner = str + 1;
        while (*runner) {
            if (*str == *runner) {
                return false;
            }

            ++runner;
        }

        ++str;
    }

    return true;
}

int main()
{
    char *unique[] = {"world", "123abc.?/*~", "aAbBcC", "", "\t\n "};
    char *not_unique[] = {"hello", "  "};

    for (int i = 0; i < sizeof(unique) / sizeof(unique[0]); ++i) {
        bool result = is_unique_follow_up(unique[i]);
        if (result == true) {
            printf("'%s' is unique.\n", unique[i]);
        } else {
            printf("Incorrect result of not unique for '%s'\n", unique[i]);
        } 
    }

    for (int i = 0; i < sizeof(not_unique) / sizeof(not_unique[0]); ++i) {
        bool result = is_unique_follow_up(not_unique[i]);
        if (result == false) {
            printf("'%s' is not unique.\n", not_unique[i]);
        } else {
            printf("Incorrect result of unique for '%s'\n", not_unique[i]);
        }
    }
}
