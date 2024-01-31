#include <bits/stdc++.h>
using namespace std;
/**
 * ------------------------------------ Introducion ------------------------------------
 * Title : Minimum Falling Path Sum
 * Leetcode No : Medium
 * Difficulty : 931
 * Topic : Array, Dynamic Programming, Matrix
 * Link : https://leetcode.com/problems/minimum-falling-path-sum/
 *
 */

/**
 * ------------------------------------ Problem Statement ------------------------------------
 * Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.
 * A falling path starts at any element in the first row and chooses the element in the next row
 * that is either directly below or diagonally left/right.
 * Specifically, the next element from position (row, col) will be (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).
 *
 * Input: matrix = [[2,1,3],[6,5,4],[7,8,9]]
 * Output: 13
 * Explanation: There are two falling paths with a minimum sum as shown.
 */

// ------------------------------------ Approach 1 : Recursion ------------------------------------
int solve(vector<vector<int>> &matrix, int row, int col)
{
    if (row == matrix.size())
    {
        return 0;
    }

    int left = INT_MAX;
    if (col > 0)
    {
        left = solve(matrix, row + 1, col - 1);
    }

    int mid = solve(matrix, row + 1, col);

    int right = INT_MAX;
    if (col > matrix.size() - 1)
    {
        right = solve(matrix, row + 1, col + 1);
    }

    return min({left, mid, right}) + matrix[row][col];
}
int minFallingPathSum(vector<vector<int>> &matrix)
{
    int m = matrix.size();
    int n = matrix[0].size();
    int result = INT_MAX;

    for (int col = 0; col < n; col++)
    {
        int val = solve(matrix, 0, col);
        result = min(val, result);
    }
    return result;
}
// Time Complexity : O(3^(m * n))
// Space Complexity : O(m)

// ------------------------------------ Approach 2 : Recursion + Memoization ------------------------------------
class Solution
{
public:
    int solve(vector<vector<int>> &matrix, int row, int col, vector<vector<int>> &dp)
    {

        if (row >= matrix.size())
            return 0;
        if (dp[row][col] != -1)
            return dp[row][col];

        int left = INT_MAX;
        if (col > 0)
        {
            left = solve(matrix, row + 1, col - 1, dp);
        }

        int mid = solve(matrix, row + 1, col, dp);

        int right = INT_MAX;
        if (col + 1 < matrix[0].size())
        {
            right = solve(matrix, row + 1, col + 1, dp);
        }

        return dp[row][col] = min({left, mid, right}) + matrix[row][col];
    }
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        int result = INT_MAX;

        vector<vector<int>> dp(m, vector<int>(n, -1));
        for (int col = 0; col < n; col++)
        {
            int val = solve(matrix, 0, col, dp);
            result = min(val, result);
        }
        return result;
    }
};