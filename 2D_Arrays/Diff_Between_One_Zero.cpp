#include <vector>
using namespace std;

/**
 * ----------------------- Introduction ------------------------------------------
 * Title : Difference Between Ones and Zeros in Row and Column
 * LeetCode No : 2482
 * Difficulty : Medium
 * Topics : Array, Matrix
 * Link : https://leetcode.com/problems/difference-between-ones-and-zeros-in-row-and-column/description/
 *
 */

/**
 * ----------------------- Problem Statement ------------------------------------------
 * You are given a 0-indexed m x n binary matrix grid.
 * A 0-indexed m x n difference matrix diff is created with the following procedure:
 * - Let the number of ones in the ith row be onesRowi.
 * - Let the number of ones in the jth column be onesColj.
 * - Let the number of zeros in the ith row be zerosRowi.
 * - Let the number of zeros in the jth column be zerosColj.
 * - diff[i][j] = onesRowi + onesColj - zerosRowi - zerosColj
 *
 * Return the difference matrix diff.
 * Input: grid = [[0,1,1],[1,0,1],[0,0,1]]
 * Output: [[0,0,4],[0,0,4],[-2,-2,2]]
 *
 */

// ----------------------- Approach 1  ---------------------------------
class Solution
{
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();

        vector<int> rows(m);
        vector<int> cols(n);

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                rows[i] += grid[i][j];
                cols[j] += grid[i][j];
            }
        }
        vector<vector<int>> result(m, vector<int>(n));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                result[i][j] = (2 * rows[i] + 2 * cols[j]) - (m + n);
            }
        }
        return result;
    }
};
// TC : O(n * m)
// SC : O(n + m)