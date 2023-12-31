#include <vector>
#include <algorithm>
using namespace std;

// ----------------------- Introduction ------------------------------------------
// Title : Spiral Matrix II
// LeetCode No : 59
// Difficulty : Medium
// Topics : Array, Matrix
// Link : https://leetcode.com/problems/spiral-matrix-ii/description/

// ----------------------- Problem Statement --------------------------------------

// Given a positive integer n, generate an n x n matrix filled with elements from 1 to n2 in spiral order.

// Input: n = 3
// Output: [[1,2,3],[8,9,4],[7,6,5]]

// ----------------------- Approach 1  ---------------------------------

class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> spiral(n, vector<int>(n));

        int top = 0, bottom = n - 1;
        int left = 0, right = n - 1;

        int val = 1;
        while (val <= n * n)
        {
            // top : left ---> right
            for (int col = left; col <= right && val <= n * n; col++)
            {
                spiral[top][col] = val++;
            }
            top++;

            // right : top ----> bottom
            for (int row = top; row <= bottom && val <= n * n; row++)
            {
                spiral[row][right] = val++;
            }
            right--;

            // bottom : right ----> left
            for (int col = right; col >= left && val <= n * n; col--)
            {
                spiral[bottom][col] = val++;
            }
            bottom--;

            // left : bottom ----> top
            for (int row = bottom; row >= top && val <= n * n; row--)
            {
                spiral[row][left] = val++;
            }
            left++;
        }
        return spiral;
    }
};
// T.C : O(m * n)
// S.C : O(m * n)