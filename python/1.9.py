"""
Cracking the Coding Interview Question 1.9 String Rotation

Assume you have a method isSubstring which checks if one word is a substring of
another. Given two strings, s1 and s2, write code to check if s2 is a rotation
of s1 using only one call to isSubstring (e.g., 'waterbottle' is a rotation of
'erbottlewat').
"""

__author__ = 'Jose Rojas'

import unittest

def string_rotation(s1, s2):
    """
    Function to check if a string s2 is a rotation of another string s1

    Time Complexity: O(N)
    Space Complexity: O(1)
    """

    if len(s1) != len(s2):
        return False
    return s2 in s1 + s1

class Test(unittest.TestCase):
    data_expected_true = (
        ('hello world', 'ello worldh'),
        ('waterbottle', 'erbottlewat'))

    data_expected_false = (
        ('hello', 'helol'),
        ('water', 'bottle'))

    def test_string_rotation(self):
        for test_pair in self.data_expected_true:
            actual = string_rotation(test_pair[0], test_pair[1])
            self.assertTrue(actual)

        for test_pair in self.data_expected_false:
            actual = string_rotation(test_pair[0], test_pair[1])
            self.assertFalse(actual)

if __name__ == '__main__':
    unittest.main()
