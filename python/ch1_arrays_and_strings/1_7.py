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

    n = len(matrix)  # num of rows/cols in matrix

    # Perform rotation in layers (eg. outer layer, inner layer). Num of layers
    # in a matrix is equal to length / 2. We are dropping remainder so this can
    # work with both even and odd lengthed matrices (dropping remainder will ignore
    # middle layer of matrix which is fine because middle layer is 1 x 1 and
    # will not need a rotation.)
    for layer in range(n // 2):
        first = layer  # tracks first row and column of this layer
        last = n - layer - 1  # tracks last row and last column of this layer

        for i in range(first, last):
            offset = i - first  # used to iterate layer

            tmp = matrix[first][i]
            matrix[first][i] = matrix[last - offset][first]
            matrix[last - offset][first] = matrix[last][last - offset]
            matrix[last][last - offset] = matrix[i][last]
            matrix[i][last] = tmp

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
