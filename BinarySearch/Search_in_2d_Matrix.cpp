#include <vector>
#include <algorithm>
using namespace std;

/**
 * ----------------------- Introduction ------------------------------------------
 * Title : Search a 2D Matrix
 * Leetcode No : 74
 * Difficulty : Medium
 * Topics : Array, Binary Search, Matrix
 * Link : https://leetcode.com/problems/search-a-2d-matrix/
 *
 */

/**
 * ----------------------- Problem Statement ------------------------------------------
 * Write an efficient algorithm that searches for a value in an m x n matrix.
 * This matrix has the following properties:
 * - Integers in each row are sorted from left to right.
 * - The first integer of each row is greater than the last integer of the previous row. *
 */

// ----------------------- Approach 1 : Brute Force ---------------------------------
class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        for (vector<int> &row : matrix)
        {
            for (int &num : row)
            {
                if (num == target)
                    return true;
            }
        }
        return false;
    }
};
// TC : O(m*n)
// SC : O(1)

// ------------------------ Approach 2  ------------------------------
class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int m = matrix.size(), n = matrix[0].size();
        int i = 0, j = n - 1;
        while (i < m && j > 0)
        {
            if (matrix[i][j] == target)
                return true;

            else if (matrix[i][j] > target)
                j--;
            else
                i++;
        }
    }
};
// T.C : O(m+n)
// S.C : O(1)

// ------------------------ Approach 3 ----------------------------------------
class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        for (vector<int> &row : matrix)
        {
            if (binary_search(row.begin(), row.end(), target))
                return true;
        }
        return false;
    }
};
// TC : O(m*log(n))
// SC : O(1)

// ------------------------ Approach 4 : Optimal Approach -----------------------
class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int m = matrix.size(), n = matrix[0].size();
        int low = 0, high = m * n - 1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            int midElement = matrix[mid / n][mid % n];

            if (midElement == target)
                return true;
            else if (midElement > target)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return false;
    }
};
// TC : O(log(m*n))
// SC : O(1)
