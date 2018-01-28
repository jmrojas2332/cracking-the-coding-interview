"""
Cracking the Coding Interview Question 1.5 One Away

There are three types of edits that can be performed on strings: insert a
character, remove a character, or replace a character. Given two strings, write
a function to check if they are one edit (or zero edits) away.
"""

import unittest


def is_one_away(s1, s2):
    l1 = len(s1)
    l2 = len(s2)

    if abs(l1 - l2) > 1:  # cannot be one away if length differs by more than 1
        return False

    if l1 == l2:
        return is_one_away_replace(s1, s2, l1)
    elif l1 < l2:
        return is_one_away_insert(s1, s2, l1, l2)
    else:
        # removing from s1 to make s2 is the same as inserting into s2 to make s1
        return is_one_away_insert(s2, s1, l2, l1)

def is_one_away_replace(s1, s2, length):
    diff_count = len([1 for i in range(length) if s1[i] != s2[i]])

    return diff_count <= 1

def is_one_away_insert(shorter, longer, shorter_length, longer_length):
    found_diff = False
    shorter_idx = 0
    for longer_idx in range(longer_length):
        if shorter_idx == shorter_length:  # end of short string reached
            break
        elif shorter[shorter_idx] != longer[longer_idx]:
            if found_diff:
                return False
            else:
                found_diff = True
        else:
            shorter_idx += 1  # only increment smaller index when char is equal

    return True


class Test(unittest.TestCase):
    data_expected_true = (('bell','jell'), ('bell', 'yell'), ('bell', 'belly'), ('belly', 'bell'))
    data_expected_false = (('bell', 'jill'), ('bell', 'yeil'), ('bell', 'eil'), ('bell', 'jells'))

    def test_is_one_away(self):
        for test_pair in self.data_expected_true:
            actual = is_one_away(test_pair[0], test_pair[1])
            self.assertTrue(actual)

        for test_pair in self.data_expected_false:
            actual = is_one_away(test_pair[0], test_pair[1])
            self.assertFalse(actual)

if __name__ == '__main__':
    unittest.main()
