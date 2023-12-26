#include <vector>
#include <algorithm>
using namespace std;

// ----------------------- Introduction ------------------------------------------
// Title : Spiral Matrix
// LeetCode No : 54
// Difficulty : Medium
// Topics : Array, Matrix
// Link : https://leetcode.com/problems/spiral-matrix/description/

// ----------------------- Problem Statement --------------------------------------

// Given an m x n matrix, return all elements of the matrix in spiral order.
// Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
// Output: [1,2,3,6,9,8,7,4,5]

// ----------------------- Approach 1  ---------------------------------

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        int row = matrix.size();
        int col = matrix[0].size();

        int topRow = 0, bottomRow = row - 1;
        int leftCol = 0, rightCol = col - 1;

        vector<int> ans(row * col);
        int idx = 0; // index of ans array

        while (idx < row * col)
        {

            // topRow -> leftCol to rightCol
            for (int j = leftCol; (j <= rightCol) && (idx < row * col); j++)
            {
                ans[idx++] = matrix[topRow][j];
            }
            topRow++;

            // RightCol -> topRow to bottomRow
            for (int i = topRow; (i <= bottomRow) && (idx < row * col); i++)
            {
                ans[idx++] = matrix[i][rightCol];
            }
            rightCol--;

            // bottonRow -> rightCol to leftCol
            for (int j = rightCol; (j >= leftCol) && (idx < row * col); j--)
            {
                ans[idx++] = matrix[bottomRow][j];
            }
            bottomRow--;

            // leftCol -> bottomRow to TopRow
            for (int i = bottomRow; (i >= topRow) && (idx < row * col); i--)
            {
                ans[idx++] = matrix[i][leftCol];
            }
            leftCol++;
        }

        return ans;
    }
};
// T.C : O(m*n)
// S.C : O(1)