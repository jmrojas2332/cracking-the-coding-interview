"""
Cracking the Coding Interview

Chapter 1 Arrays and Strings

Question 1.4: Given a string, write a function to check if it is a permutation
of a palindrome. A palindrome is a word or phrase that is the same forwards as
backwards. A permutation is a rearrangement of letters. The palindrome does not
need to be limited to just dictionary words.
"""

import unittest

ALPHABET_SIZE = 256

def palindrome_permutation(string):
	"""
	Function to check if a string is a palindrome permution
	Firse check how many times every character in our alphabet appears in the
	string. Then return false if more than only 1 character has an odd count.
	Otherwise, we return false.

	Note: We are using extended ascii as our alphabet (see ALPHABET_SIZE) and
		  our solution handles lowercase and uppercase as different characters
	"""

	

	char_count = [0] * ALPHABET_SIZE

	for c in string:
		val = ord(c)
		if val >= ALPHABET_SIZE:
			raise IndexError('Character {0} with value {1} not in our alphabet of size {2}'.format(
				c,
				val, 
				ALPHABET_SIZE))
		else:
			char_count[val] += 1

	odd_found = False
	for count in char_count:
		if count % 2 == 1:
			if odd_found:
				return False
			else:
				odd_found = True

	return True



class Test(unittest.TestCase):
	data_expected_true = ['aabb', 'aabbc', '01010101', ' ', 'a', 'hello hello']
	data_expected_false = ['aaab', 'aabbcd', '010101', 'Hello hello']

	def test_palindrome_permutation(self):
		for test_string in self.data_expected_true:
			actual = palindrome_permutation(test_string)
			self.assertTrue(actual)

		for test_string in self.data_expected_false:
			actual = palindrome_permutation(test_string)
			self.assertFalse(actual)


if __name__ == '__main__':
	unittest.main()