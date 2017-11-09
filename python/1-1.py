"""
Cracking the Coding Interview Question 1.1 Is Unique

Implement an algorithm to determine if a string has all unique characters. What
if you cannot use additional data structures?
"""

__author__ = 'Jose Rojas'

import unittest


def is_unique(string):
    """
    Function for checking if one string has a unique set of characters.

    Function iterates through the string, inserting characters into a set if the
    character does not already exist in the set, returning False if it does.

    Time Complexity: O(n) where n is the length of the string
    Space Complexity: O(k) where k is the size of the alphabet (ASCII or Unicode)
    """

    char_set = set()
    for c in string:
        if c in char_set:
            return False
        char_set.add(c)

    return True

def is_unique_no_storage(string):
    """
    Function for checking if one string has a unique set of characters.

    Function compares every character to every other character.

    Time Complexity: O(n^2) where n is the length of the string
    Space Complexity: O(1)
    """

    length = len(string)
    for i in range(length - 1):
        for j in range(i + 1, length):
            if string[i] == string[j]:
                return False

    return True

class Test(unittest.TestCase):
    data_expected_true = ('abcd', 'jose', 'rojas', 'world')
    data_expected_false = ('hello', 'good', 'buddy')

    def test_is_unique(self):
        for test_string in self.data_expected_true:
            actual = is_unique(test_string)
            self.assertTrue(actual)

        for test_string in self.data_expected_false:
            actual = is_unique(test_string)
            self.assertFalse(actual)

if __name__ == '__main__':
    unittest.main()
