"""
Cracking the Coding Interview Question 1.2 Check Permutation

Given two strings, write a method to decide if one is a permutation of the other.
"""

from collections import Counter # dict; keys are chars and values are char counts
import unittest


def is_permutation(s1, s2):
    if len(s1) != len(s2):  # must have equal length to be a permutation
        return False

    char_counter = Counter(s1)

    for c in s2:
        if c in char_counter:
            char_counter[c] -= 1
            if char_counter[c] < 0:  # more of character c in s2 than in s1
                return False
        else:  # if not already in dict then it was not in s1
            return False

    return True

def is_permutation_with_sort(s1, s2):
    if len(s1) != len(s2):  # must have equal length to be a permutation
        return False

    return sorted(s1) == sorted(s2)  # sorted strings with same value are permutations

class Test(unittest.TestCase):
    data_expected_true = (('a','a'), ('ab', 'ba'), ('001', '100'), (' a', 'a '))
    data_expected_false = (('a', 'A'), ('ab', 'ac'), ('', ' '))

    def test_is_permutation(self):
        for str1, str2 in self.data_expected_true:
            actual = is_permutation(str1, str2)
            self.assertTrue(actual)

        for str1, str2 in self.data_expected_false:
            actual = is_permutation(str1, str2)
            self.assertFalse(actual)

if __name__ == '__main__':
    unittest.main()
