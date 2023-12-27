#include <vector>
using namespace std;

// ----------------------- Introduction ------------------------------------------
// Title : Where Will the Ball Fall
// LeetCode No : 1706
// Difficulty : Medium
// Topics : Array, Matrix
// Link : https://leetcode.com/problems/where-will-the-ball-fall/

// ----------------------- Problem Statement --------------------------------------

// You have a 2-D grid of size m x n representing a box, and you have n balls. The box is open on the top and bottom sides.

// Each cell in the box has a diagonal board spanning two corners of the cell that can redirect a ball to the right or to the left.
// 1. A board that redirects the ball to the right spans the top-left corner to the bottom-right corner and is represented in the grid as 1.
// 2. A board that redirects the ball to the left spans the top-right corner to the bottom-left corner and is represented in the grid as -1.

// We drop one ball at the top of each column of the box. Each ball can get stuck in the box or fall out of the bottom.
// A ball gets stuck if it hits a "V" shaped pattern between two boards or if a board redirects the ball into either wall of the box.

// Return an array answer of size n where answer[i] is the column that the ball falls out of at the bottom after dropping the ball from the ith column
// at the top, or -1 if the ball gets stuck in the box.

// Input: grid = [[1,1,1,-1,-1],[1,1,1,-1,-1],[-1,-1,-1,1,1],[1,1,1,1,-1],[-1,-1,-1,-1,-1]]
// Output: [1,-1,-1,-1,-1]

// -------------------------------- Approach 1  ---------------------------------
class Solution
{
public:
    vector<int> findBall(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> ans(n);
        for (int ball = 0; ball < n; ball++)
        {
            int row = 0;
            int col = ball;
            while (row < m)
            {

                if (grid[row][col] == -1)
                {
                    if (col == 0 || grid[row][col - 1] == 1)
                    {
                        ans[ball] = -1;
                        break;
                    }
                    col = col - 1;
                }
                else if (grid[row][col] == 1)
                {
                    if (col == n - 1 || grid[row][col + 1] == -1)
                    {
                        ans[ball] = -1;
                        break;
                    }
                    col = col + 1;
                }
                row = row + 1;

                if (row == m)
                    ans[ball] = col;
            }
        }
        return ans;
    }
};
// T.C : O(m*n)
// S.C : O(1)