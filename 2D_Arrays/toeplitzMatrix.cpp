#include <vector>
using namespace std;

// ----------------------- Introduction ------------------------------------------
// Title : Diagonal Traverse
// LeetCode No : 766
// Difficulty : Easy
// Topics : Array, Matrix
// Link : https://leetcode.com/problems/toeplitz-matrix/description/

// ----------------------- Problem Statement --------------------------------------
// Given an m x n matrix, return true if the matrix is Toeplitz. Otherwise, return false.
// A matrix is Toeplitz if every diagonal from top-left to bottom-right has the same elements.

// Input: matrix = [[1,2,3,4],[5,1,2,3],[9,5,1,2]]
// Output: true

// -------------------------------- Approach 1  ---------------------------------
class Solution
{
public:
    bool isToeplitzMatrix(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();

        for (int i = 1; i < m; i++)
        {
            for (int j = i; j < n; j++)
            {
                if (matrix[i][j] != matrix[i - 1][j - 1])
                    return false;
            }
        }
        return true;
    }
};
// T.C : O(m * n)
// S.C : O(1)