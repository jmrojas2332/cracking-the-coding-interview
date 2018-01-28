"""
Cracking the Coding Interview Question 1.9 String Rotation

Assume you have a method isSubstring which checks if one word is a substring of
another. Given two strings, s1 and s2, write code to check if s2 is a rotation
of s1 using only one call to isSubstring (e.g., 'waterbottle' is a rotation of
'erbottlewat').
"""

import unittest


def is_substring(string, sub):
    return sub in string

def is_rotation(s1, s2):
    if len(s1) != len(s2):  # must be equal in length to be rotation
        return False

    # a string is a rotation if it is a substring of a string appended to itself
    # e.g. 'waterbottle' is a substring of 'erbottlewat' + 'erbottlewat' making it
    # a rotation of 'erbottlewat'
    return is_substring(s1 + s1, s2)

class Test(unittest.TestCase):
    data_expected_true = (
        ('hello world', 'ello worldh'),
        ('waterbottle', 'erbottlewat'))

    data_expected_false = (
        ('hello', 'helol'),
        ('water', 'bottle'))

    def test_is_rotation(self):
        for test_pair in self.data_expected_true:
            actual = is_rotation(test_pair[0], test_pair[1])
            self.assertTrue(actual)

        for test_pair in self.data_expected_false:
            actual = is_rotation(test_pair[0], test_pair[1])
            self.assertFalse(actual)

if __name__ == '__main__':
    unittest.main()
