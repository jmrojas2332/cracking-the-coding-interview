"""
Cracking the Coding Interview Question 1.4 Palindrome Permutation

Given a string, write a function to check if it is a permutation of a
palindrome. A palindrome is a word or phrase that is the same forwards as
backwards. A permutation is a rearrangement of letters. The palindrome does not
need to be limited to just dictionary words.
"""

from collections import Counter
import unittest


def is_palindrome_permutation(string):
    char_counter = Counter(string)  # dict where keys are chars and values are char counts of s1
    odd_count = len([1 for count in char_counter.values() if count % 2 == 1])

    return odd_count <= 1

class Test(unittest.TestCase):
    data_expected_true = ('aabb', 'aabbc', '01010101', ' ', 'a', 'hello hello')
    data_expected_false = ('aaab', 'aabbcd', '010101', 'Hello hello')

    def test_is_palindrome_permutation(self):
        for test_string in self.data_expected_true:
            actual = is_palindrome_permutation(test_string)
            self.assertTrue(actual)

        for test_string in self.data_expected_false:
            actual = is_palindrome_permutation(test_string)
            self.assertFalse(actual)

if __name__ == '__main__':
    unittest.main()
