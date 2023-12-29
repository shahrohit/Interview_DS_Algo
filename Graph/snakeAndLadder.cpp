#include <vector>
#include <queue>
using namespace std;

// ----------------------- Introduction ------------------------------------------
// Title : Snakes and Ladders
// LeetCode No : 909
// Difficulty : Medium
// Topics : Array, Matrix, BFS
// Link : https://leetcode.com/problems/snakes-and-ladders/description/

// ----------------------- Problem Statement --------------------------------------
// Input: board = [
// [-1,-1,-1,-1,-1,-1],
// [-1,-1,-1,-1,-1,-1],
// [-1,-1,-1,-1,-1,-1],
// [-1,35,-1,-1,13,-1],
// [-1,-1,-1,-1,-1,-1],
// [-1,15,-1,-1,-1,-1]
// ]
// Output: 4
// ----------------------- Approach 1 ---------------------------------
class Solution
{
public:
    pair<int, int> getCoordinate(int num, int n)
    {

        int row = (n - 1) - (num - 1) / n;

        int col = (num - 1) % n;
        if ((n % 2 == 0 && row % 2 == 0) || (n % 2 == 1 && row % 2 == 1))
        {
            col = (n - 1) - col;
        }
        return {row, col};
    }
    int snakesAndLadders(vector<vector<int>> &board)
    {
        int n = board.size();
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        queue<int> que;
        que.push(1);
        visited[n - 1][0] = true;
        int steps = 0;

        while (!que.empty())
        {
            int N = que.size();
            while (N--)
            {
                int x = que.front();
                que.pop();

                if (x == n * n)
                    return steps;

                for (int k = 1; k <= 6; k++)
                {
                    int val = x + k;
                    if (val > n * n)
                        break;
                    pair<int, int> coord = getCoordinate(val, n);
                    int r = coord.first;
                    int c = coord.second;

                    if (visited[r][c] == true)
                        continue;

                    visited[r][c] = true;
                    if (board[r][c] == -1)
                    {
                        que.push(val);
                    }
                    else
                    {
                        que.push(board[r][c]);
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};
// T.C : O(n * n)
// S.C : O(n * n)