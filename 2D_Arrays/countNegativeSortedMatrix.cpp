#include <vector>
#include <algorithm>
using namespace std;

// ----------------------- Introduction ------------------------------------------
// Title : Count Negative Numbers in a Sorted Matrix
// LeetCode No : 1351
// Difficulty : Easy
// Topics : Array, Matrix
// Link : https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/description/

// ----------------------- Problem Statement --------------------------------------

// Given an m x n matrix mat, return an array of all the elements of the array in a diagonal order

// Input: grid = [[4,3,2,-1],[3,2,1,-1],[1,1,-1,-2],[-1,-1,-2,-3]]
// Output: 8
// Explanation: There are 8 negatives number in the matrix.

// ----------------------- Approach 1  ---------------------------------

class Solution
{
public:
    int countNegatives(vector<vector<int>> &grid)
    {
        int count = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = grid[0].size() - 1; j >= 0; j--)
            {
                if (grid[i][j] < 0)
                    count++;
                else
                    break;
            }
        }
        return count;
    }
};

// T.C : O(m * n)
// S.C : O(1)

// ----------------------- Approach 2 : Binary Search  ---------------------------------
class Solution
{
public:
    int countNegatives(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        int count = 0;
        for (auto &row : grid)
        {
            // find the first negative number
            auto idx = upper_bound(begin(row), end(row), 0, greater<int>()) - begin(row);

            count += (n - idx);
        }
        return count;
    }
};
// T.C : O(m * log(n))

// ----------------------- Approach 3  ---------------------------------
// Matrix is sorted
class Solution
{
public:
    int countNegatives(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        int i = 0, j = n - 1;

        int count = 0;
        while (i < m && j >= 0)
        {
            // if element is 0 then remaing all nums in the same column will be negative
            // then go for the j-1 column
            if (grid[i][j] < 0)
            {
                count += (m - i);
                j--;
            }
            else // increase the row to get the first negative number in a same column
            {
                i++;
            }
        }
        return count;
    }
};
// T.C : O(m + n)
// S.C : (1)