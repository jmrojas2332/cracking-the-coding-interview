"""
Cracking the Coding Interview Question 1.7 Rotate Matrix

Given an image represented by an NxN matrix, where each pixel in the image is 4
bytes, write a method to rotate the image by 90 degrees. Can you do this in
place?

Note: Will be rotating clockwise and rotating integers (eg. top left number will
be rotated to top right (see test case))
"""

import unittest

def rotate_matrix(matrix):
    # Perform rotation in layers (eg. outer layer, inner layer). Num of layers
    # in a matrix is equal to length / 2. Since this is python we need to cast
    # to integer since division of a matrix with odd length will give back a
    # float. The cast will drop the decimal giving us what we want since we
    # don't need to rotate middle (only one number in middlemost layer of a
    # matrix with odd length).

    n = len(matrix)  # num of rows/cols in matrix

    for layer in range(n // 2):
        first = layer
        last = n - layer - 1

        for i in range(first, last):
            offset = i - first
            tmp = matrix[first][i]
            matrix[first][i] = matrix[last - offset][first]
            matrix[last - offset][first] = matrix[last][last - offset]
            matrix[last][last - offset] = matrix[i][last]
            matrix[i][last] = tmp
        print(matrix)

class Test(unittest.TestCase):
    test1 = {'actual' : [[0, 0, 0],
                         [1, 1, 1],
                         [0, 0, 0]],
             'expected' : [[0, 1, 0],
                           [0, 1, 0],
                           [0, 1, 0]]}

    test2 = {'actual' : [[0, 0, 0, 1],
                         [3, 4, 5, 1],
                         [3, 7, 6, 1],
                         [3, 2, 2, 2]],
             'expected' : [[3, 3, 3, 0],
                           [2, 7, 4, 0],
                           [2, 6, 5, 0],
                           [2, 1, 1, 1]]}

    data = [test1, test2]

    def test_rotate_matrix(self):
        for matrix in self.data:
            rotate_matrix(matrix['actual'])
            self.assertEqual(matrix['actual'], matrix['expected'])

if __name__ == '__main__':
    unittest.main()
