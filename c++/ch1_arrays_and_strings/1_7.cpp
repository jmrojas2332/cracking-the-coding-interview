// Cracking the Coding Interview Question 1.7 Rotate Matrix
//
// Given an image represented by an NxN matrix, where each pixel in the image is 4
// bytes, write a method to rotate the image by 90 degrees. Can you do this in
// place?
//
// Note: Will be rotating clockwise and rotating integers (eg. top left number will
// be rotated to top right (see test case))

#include <iostream>
#include <string>

template <int Size>
void rotateMatrix(int matrix[][Size])
{
    for (int layer = 0; layer < Size / 2; ++layer)
    {
        int last_idx = Size - layer - 1;

        for (int i = layer; i < last_idx; ++i)
        {
            int offset = i - layer;

            // copy top -> temp
            int tmp = matrix[layer][i];

            // copy left -> top
            matrix[layer][i] = matrix[last_idx - offset][layer];

            // copy bottom -> left
            matrix[last_idx - offset][layer] = matrix[last_idx][last_idx - offset];

            // copy right -> bottom
            matrix[last_idx][last_idx - offset] = matrix[i][last_idx];

            // copy top (from temp) -> right
            matrix[i][last_idx] = tmp;
        }
    }
}

template <int Size>
std::string getMatrixAsString(int matrix[][Size])
{
    std::string format = "";
    format.reserve(Size * Size);  // avoid excess allocations by reserving ahead of time

    for (int row = 0;  row < Size; ++row)
    {
        format += "[";
        for (int col = 0; col < Size; ++col)
        {
            format += std::to_string(matrix[row][col]) + ", ";
        }
        format += "\b\b]\n";  // remove trailing comma/space from last element in row before moving to next row
    }

    return format;
}

int main()
{
    int matrix3[3][3]
    {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int matrix4[4][4]
    {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {8, 10, 11, 12},
        {13, 14, 15, 16}
    };

    int matrix5[5][5]
    {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}
    };

    std::cout << getMatrixAsString<3>(matrix3) << "\n";
    rotateMatrix<3>(matrix3);
    std::cout << getMatrixAsString<3>(matrix3) << "\n";

    std::cout << getMatrixAsString<4>(matrix4) << "\n";
    rotateMatrix<4>(matrix4);
    std::cout << getMatrixAsString<4>(matrix4) << "\n";

    std::cout << getMatrixAsString<5>(matrix5) << "\n";
    rotateMatrix<5>(matrix5);
    std::cout << getMatrixAsString<5>(matrix5) << "\n";

    return 0;
}
