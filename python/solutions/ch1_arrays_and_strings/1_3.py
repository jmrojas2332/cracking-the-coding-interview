"""
Cracking the Coding Interview Question 1.3 URLify

Write a method to replace all spaces in a string with '%20'. You may assume that
the string has sufficient space at the end to hold the additional characters,
and that you are given the 'true' length of the string. (Note: If implementing
in language with immutable strings, please use a character array so that you can
perfrom this operation in place.)

Note: using python's built-in list type because it is essentially an array
"""

import unittest


def urlify(char_list, length):
    idx_end = len(char_list)  # get the position at the end of the list

    for idx in reversed(range(length)):  # from last char's position to first
        if char_list[idx] == ' ':
            char_list[idx_end - 3: idx_end] = '%20'
            idx_end -= 3
        else:
            char_list[idx_end - 1] = char_list[idx]
            idx_end -= 1

class Test(unittest.TestCase):
    data = (
        (list('Hello World  '), 11, list('Hello%20World')),
        (list('Mr Jose Rojas    '), 13, list('Mr%20Jose%20Rojas')))

    def test_urlify(self):
        for [actual, length, expected] in self.data:
            urlify(actual, length)
            self.assertEqual(actual, expected)

if __name__ == '__main__':
    unittest.main()
