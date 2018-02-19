"""
Cracking the Coding Interview Question 1.6 String Compression

Implement a method to perform basic string compression using the counts of
repeated characters. For example, string aabcccccaaa would become a2b1c5a3. If
the "compressed" string would not become smaller than the original string, your
method should return the original string. You can assume the string has only
uppercase and lowercase letter (a-z).
"""

import unittest


def compress_string(string):
    compressed_string = []
    current_count = 0

    for i in range(len(string)):
        if i != 0 and string[i] != string[i-1]:
            compressed_string.append(string[i - 1] + str(current_count))
            current_count = 0
        current_count += 1

    compressed_string.append(string[i - 1] + str(current_count)) # add last char

    return min(string, ''.join(compressed_string), key=len)

class Test(unittest.TestCase):
    data = (('aabcccccaaa', 'a2b1c5a3'), ('abc', 'abc'), ('aabbccc', 'a2b2c3'))

    def test_compress_string(self):
        for test_pair in self.data:
            expected = test_pair[1]
            actual = compress_string(test_pair[0])
            self.assertEqual(expected, actual)

if __name__ == '__main__':
    unittest.main()
