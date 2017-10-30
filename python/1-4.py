"""
Cracking the Coding Interview Question 1.4 Palindrome Permutation

Given a string, write a function to check if it is a permutation of a
palindrome. A palindrome is a word or phrase that is the same forwards as
backwards. A permutation is a rearrangement of letters. The palindrome does not
need to be limited to just dictionary words.
"""

__author__ = 'Jose Rojas'

import unittest

def palindrome_permutation(string):
    """
    Function to check if a string is a palindrome permutation

    Function counts how many characters appear an odd amount of times in the
    string. In order to be a permutation of a palindrome there can be at most 1
    character that appears an odd amount of times.

    Returns True if at most 1 character has an odd count. Else Returns False

    Time Complexity: O(n) where n is the length of 'string'
    Space Complexity: O(k) where k is the number of unique characters in 'string'
    """

    char_dict = dict()
    odd_count = 0

    for c in string:
        val = c

        if val in char_dict:
            char_dict[val] += 1
        else:
             char_dict[val] = 1

        if char_dict[val] % 2 == 1:    # if odd
            odd_count += 1
        else:
            odd_count -= 1

    return odd_count <= 1

class Test(unittest.TestCase):
    data_expected_true = ('aabb', 'aabbc', '01010101', ' ', 'a', 'hello hello')
    data_expected_false = ('aaab', 'aabbcd', '010101', 'Hello hello')

    def test_palindrome_permutation(self):
        for test_string in self.data_expected_true:
            actual = palindrome_permutation(test_string)
            self.assertTrue(actual)

        for test_string in self.data_expected_false:
            actual = palindrome_permutation(test_string)
            self.assertFalse(actual)


if __name__ == '__main__':
    unittest.main()
