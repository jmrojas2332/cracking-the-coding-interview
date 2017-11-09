"""
Cracking the Coding Interview Question 1.8 Zero Matrix

Write an algorithm such that if an element in an M x N matrix is 0, its entire
row and column are set to 0.
"""

__author__ = 'Jose Rojas'

import unittest


def zero_matrix(matrix):
    """
    Function for filling the matrices rows/columns that contain a zero.

    Function uses first row and col of matrix to track which rows and cols will
    have zeros.

    Function first checks if 1st row/col of matrix will contain zeros, then
    traverses remaining matrix, tracking which rows/cols will contain zeros.
    Function concludes by traversing matrix again, nullifying matrix using 1st
    row/col.

    Time Complexity: O(m x n) where m x n are the dimensions of the matrix
    Space Complexity: O(1)
    """

    rows = len(matrix)
    cols = len(matrix[0])
    zerorow = False
    zerocol = False

    # initial check of matrix containing zeros in 1st row or col
    for c in range(cols):
        if not matrix[0][c]:
            zerorow = True
            break
    for r in range(rows):
        if not matrix[r][0]:
            zerocol = True
            break

    # traverse matrix, excluding 1st row/col, tracking rows/cols that contain zeros
    for r in range(1, rows):
        for c in range(1, cols):
            if not matrix[r][c]:
                matrix[0][c] = 0
                matrix[r][0] = 0

    # nullify matrix values, excluding 1st row/col, using 1st row/col
    for r in range(1, rows):
        for c in range(1, cols):
            if not matrix[0][c] or not matrix[r][0]:
                matrix[r][c] = 0

    # nullify first row and col if initial check deemed zeros necessary
    if zerorow:
        for c in range(cols):
            matrix[0][c] = 0
    if zerocol:
        for r in range(rows):
            matrix[r][0] = 0

class Test(unittest.TestCase):
    test1 = {'actual' : [[1, 2, 3],
                         [0, 3, 1]],

             'expected' : [[0, 2, 3],
                           [0, 0, 0]]}

    test2 = {'actual' : [[2, 3, 0],
                         [1, 2, 2],
                         [3, 3, 3]],
             'expected' : [[0, 0, 0],
                           [1, 2, 0],
                           [3, 3, 0]]}

    test3 = {'actual' : [[0, 1, 2]],
             'expected' : [[0, 0, 0]]}

    data = [test1, test2, test3]

    def test_zero_matrix(self):
        for matrix in self.data:
            zero_matrix(matrix['actual'])
            self.assertEqual(matrix['actual'], matrix['expected'])

if __name__ == '__main__':
    unittest.main()
