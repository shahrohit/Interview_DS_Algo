#include <cstring>
#include <vector>
#include <queue>

using namespace std;
// ----------------------- Introduction ------------------------------------------
// Title : Shortest Path in a Grid with Obstacles Elimination
// LeetCode No : 1293
// Difficulty : Hard
// Topics : Array, BFS, Matrix
// Link : https://leetcode.com/problems/shortest-path-in-a-grid-with-obstacles-elimination/description/

// ----------------------- Problem Statement --------------------------------------

// You are given an m x n integer matrix grid where each cell is either 0 (empty) or 1 (obstacle).
// You can move up, down, left, or right from and to an empty cell in one step.
// Return the minimum number of steps to walk from the upper left corner (0, 0) to the lower right corner (m - 1, n - 1)
// given that you can eliminate at most k obstacles. If it is not possible to find such walk return -1.

// Input: grid = [[0,0,0],[1,1,0],[0,0,0],[0,1,1],[0,0,0]], k = 1
// Output: 6
// Explanation:
// The shortest path without eliminating any obstacle is 10.
// The shortest path with one obstacle elimination at position (3,2) is 6.
// Such path is (0,0) -> (0,1) -> (0,2) -> (1,2) -> (2,2) -> (3,2) -> (4,2).

// ------------------------------ Approach 1 ----------------------------------------

class Solution
{
public:
    int directions[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    int shortestPath(vector<vector<int>> &grid, int k)
    {

        int m = grid.size();
        int n = grid[0].size();
        queue<vector<int>> que;
        int i = 0, j = 0;
        que.push({0, 0, k});
        int visited[41][41][1601];
        memset(visited, false, sizeof(visited));
        int steps = 0;
        while (!que.empty())
        {
            int size = que.size();

            for (int i = 0; i < size; i++)
            {
                auto front = que.front();
                que.pop();
                int currRow = front[0];
                int currCol = front[1];
                int obs = front[2];

                if (currRow == m - 1 && currCol == n - 1)
                    return steps;

                for (auto &dir : directions)
                {
                    int newRow = currRow + dir[0];
                    int newCol = currCol + dir[1];

                    if (newRow < 0 || newRow >= m || newCol < 0 || newCol >= n)
                        continue;

                    int val = grid[newRow][newCol];

                    if (val == 0 && !visited[newRow][newCol][obs])
                    {
                        que.push({newRow, newCol, obs});
                        visited[newRow][newCol][obs] = true;
                    }
                    else if (val == 1 && obs > 0 && !visited[newRow][newCol][obs - 1])
                    {
                        que.push({newRow, newCol, obs - 1});
                        visited[newRow][newCol][obs - 1] = true;
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};
// T.C :  O(n * n)
// S.C : O(n * n)
