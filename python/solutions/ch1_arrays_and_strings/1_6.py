"""
Cracking the Coding Interview Question 1. String Compression

Implement a method to perform basic string compression using the counts of
repeated characters. For example, string aabcccccaaa would become a2b1c5a3. If
the "compressed" string would not become smaller than the original string, your
method should return the original string. You can assume the string has only
upercase and lowercase letter (a-z).
"""

__author__ = 'Jose Rojas'

import unittest


def compress_string(string):
    compressed_length = get_compressed_length(string)
    if len(string) <= compressed_length:
        return string

    compressed_string = []
    current_char = ''
    current_count = 0
    for c in string:
        if c == current_char:
            current_count += 1
        else:
            if current_char != '':
                compressed_string.append(f'{current_char}{current_count}')
            current_char = c
            current_count = 1

    compressed_string.append(f'{current_char}{current_count}')  # print last char

    return ''.join(compressed_string)

def get_compressed_length(string):
    current_char = ''
    char_changes = 0
    for c in string:
        if c != current_char:
            char_changes += 1
            current_char = c

    return char_changes * 2

class Test(unittest.TestCase):
    data = (('aabcccccaaa', 'a2b1c5a3'), ('abc', 'abc'), ('aabbccc', 'a2b2c3'))

    def test_compress_string(self):
        for test_pair in self.data:
            expected = test_pair[1]
            actual = compress_string(test_pair[0])
            self.assertEqual(expected, actual)

if __name__ == '__main__':
    unittest.main()
