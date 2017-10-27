"""
Cracking the Coding Interview Question 1.4 Palindrome Permutation

Given a string, write a function to check if it is a permutation of a
palindrome. A palindrome is a word or phrase that is the same forwards as
backwards. A permutation is a rearrangement of letters. The palindrome does not
need to be limited to just dictionary words.
"""

__author__ = 'Jose Rojas'

import unittest

EXTENDED_ASCII_SIZE = 256

def palindrome_permutation(string):
    """
    Function to check if a string is a palindrome permution

    Function checks how many times each character appears in the string.
    Returns True if at most 1 character has an odd count.

    Note: We are using extended ascii as our alphabet (see EXTENDED_ASCII_SIZE)
    and our solution handles lowercase and uppercase as different characters.

    Time Complexity: O(n) where n is the length of the string
    Space Complexity: O(k) where k is the size of the alphabet
    """

    char_count = [0 for _ in range(0, EXTENDED_ASCII_SIZE)]
    odd_count = 0

    for c in string:
        val = ord(c)
        if val >= EXTENDED_ASCII_SIZE:
            raise IndexError('Character {} is not in our alphabet'.format(c))
        else:
            char_count[val] += 1

            if char_count[val] % 2 == 1:
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
