"""
Cracking the Coding Interview Question 1.2 Check Permutation

Given two strings, write a method to decide if one is a permutation of the other.
"""

__author__ = 'Jose Rojas'

import unittest


def check_permutation(s1, s2):
    """
    Function for checking if one string is a permutation of the other.

    Function keeps track of a count for each char in the strings, returning
    False if a single character count is different. Else Returns True.

    Time Complexity: O(n) where n is the length of the strings
    Space Complexity: O(k) where k is the size of the char set (ASCII or Unicode)
    """

    if len(s1) != len(s2):      # must have equal length to be permutation
        return False

    char_dict = dict()
    for c in s1:
        if c in char_dict:
            char_dict[c] += 1
        else:
            char_dict[c] = 1

    for c in s2:
        if c in char_dict:
            char_dict[c] -= 1
            if char_dict[c] < 0:   # more of 'c' in s2 than in s1
                return False
        else:
            return False        # if not already in dict than it was not in s1

    return True

def check_permutation_with_sort(s1, s2):
    """
    Function for checking if one string is a permutation of the other.

    Function uses python's sorted (Tim Sort) function to sort strings and then
    compares them.

    Time Complexity: O(nlogn)
    Space Complexity: O(n)
    """

    if len(s1) != len(s2):      # must have equal length to be permutation
        return False

    return sorted(s1) == sorted(s2)

class Test(unittest.TestCase):
    data_expected_true = (('no','on'), ('came', 'mace'))
    data_expected_false = (('jose', 'rojas'), ('hello', 'world'))

    def test_check_permutation(self):
        for test_pair in self.data_expected_true:
            actual = check_permutation(test_pair[0], test_pair[1])
            self.assertTrue(actual)

        for test_pair in self.data_expected_false:
            actual = check_permutation(test_pair[0], test_pair[1])
            self.assertFalse(actual)

if __name__ == '__main__':
    unittest.main()
