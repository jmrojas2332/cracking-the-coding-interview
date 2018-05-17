"""
Cracking the Coding Interview Question 1.2 Check Permutation

Given two strings, write a method to decide if one is a permutation of the other.
"""

from collections import Counter
import unittest


def is_permutation(s1, s2):
    if len(s1) != len(s2):  # must have equal length to be a permutation
        return False

    char_counter = Counter(s1)  # dict where keys are chars and values are char counts of s1

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
    data_expected_true = (('no','on'), ('came', 'mace'))
    data_expected_false = (('jose', 'rojas'), ('hello', 'world'))

    def test_is_permutation(self):
        for test_pair in self.data_expected_true:
            actual = is_permutation(test_pair[0], test_pair[1])
            self.assertTrue(actual)

        for test_pair in self.data_expected_false:
            actual = is_permutation(test_pair[0], test_pair[1])
            self.assertFalse(actual)

if __name__ == '__main__':
    unittest.main()
