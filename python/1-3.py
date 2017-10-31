"""
Cracking the Coding Interview Question 1.3 URLify

Write a method to replace all spaces in a string with '%20'. You may assume that
the string has sufficient space at the end to hold the additional characters,
and that you are given the 'true' length of the string. (Note: If implementing
in language with immutable strings, please use a character array so that you can
perfrom this operation in place.)
"""

__author__ = 'Jose Rojas'

import unittest

def urlify(string, length):
    """
    Function to urlify a string.

    Function iterates through 'string' starting at the end, shifting each
    character towards the end of the list and replacing spaces with '%20'.

    Time Complexity: O(n) where n is the size of the list
    Space Complexity: O(1)
    """
    new_length = len(string)

    for idx in reversed(range(length)):
        if string[idx] == ' ':
            string[new_length - 3: new_length] = '%20'
            new_length -= 3
        else:
            string[new_length - 1] = string[idx]
            new_length -= 1

class Test(unittest.TestCase):

    data = [
        (list('Hello World  '), 11, list('Hello%20World')),
        (list('Mr Jose Rojas    '), 13, list('Mr%20Jose%20Rojas'))]

    def test_urlify(self):
        for [actual, length, expected] in self.data:
            urlify(actual, length)
            self.assertEqual(actual, expected)


if __name__ == '__main__':
    unittest.main()
