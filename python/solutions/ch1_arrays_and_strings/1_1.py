"""
Cracking the Coding Interview Question 1.1 Is Unique

Implement an algorithm to determine if a string has all unique characters. What
if you cannot use additional data structures?
"""

__author__ = 'Jose Rojas'

import unittest


def is_unique(string):
    return len(string) == len(set(string))  # set doesn't allow duplicates

def is_unique_no_storage(string):
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
