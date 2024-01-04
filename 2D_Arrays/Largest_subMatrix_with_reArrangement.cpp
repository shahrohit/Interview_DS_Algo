#include <vector>
#include <algorithm>
using namespace std;

/**
 * ------------------------------------ Introducion ------------------------------------
 * Title : Largest Submatrix With Rearrangements
 * LeetCode No : 1727
 * Diffulty : Medium
 * Topic : Array, Matrix, Sorting
 * Link : https://leetcode.com/problems/largest-submatrix-with-rearrangements/
 */

/**
 * ------------------------------------ Problem Statement ------------------------------------
 * You are given a binary matrix matrix of size m x n, and you are allowed
 * to rearrange the columns of the matrix in any order.
 * Return the area of the largest submatrix within matrix where
 * every element of the submatrix is 1 after reordering the columns optimally.
 *
 *  Input: matrix = [[0,0,1],[1,1,1],[1,0,1]]
 * Output: 4
 * Explanation: You can rearrange the columns as shown above.
 * The largest submatrix of 1s, in bold, has an area of 4.
 *
 */

// ------------------------------------ Approach 1 ------------------------------------
class Solution
{
public:
    int largestSubmatrix(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();

        int maxArea = 0;
        for (int i = 1; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == 1 && i > 0)
                {
                    matrix[i][j] += matrix[i - 1][j];
                }
            }

            vector<int> heights = matrix[i];
            sort(heights.begin(), heights.end(), greater<int>());

            for (int i = 0; i < n; i++) // O(n)
            {
                if (heights[i] == 0)
                    break;

                int ht = heights[i];
                int base = i + 1;

                int currArea = ht * base;
                maxArea = max(maxArea, currArea);
            }
        }
        return maxArea;
    }
};
// T.C : O(m* n *log(n))
// S.C : O(m * n)

// ------------------------------------ Approach 2 ------------------------------------
class Solution
{
public:
    int largestSubmatrix(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();

        int maxArea = 0;
        vector<int> currRow(n, 0);
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == 1)
                {
                    currRow[j] += matrix[i][j];
                }
                else
                    currRow[j] = 0;
            }
            vector<int> heights = currRow;
            sort(heights.begin(), heights.end(), greater<int>());

            for (int i = 0; i < n; i++)
            {
                if (heights[i] == 0)
                    break;

                int ht = heights[i];
                int base = i + 1;

                int currArea = ht * base;
                maxArea = max(maxArea, currArea);
            }
        }
        return maxArea;
    }
};
// T.C : O(m* n *log(n))
// S.C : O(n)

// ------------------------------------ Approach 3 ------------------------------------
class Solution
{
public:
    int largestSubmatrix(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();

        int maxArea = 0;
        // pair<height, col>
        vector<pair<int, int>> prevHeight;
        for (int row = 0; row < m; row++)
        {
            vector<pair<int, int>> currHeight;
            vector<bool> seen(n, false);

            for (auto [height, col] : prevHeight)
            {
                if (matrix[row][col] == 1)
                {
                    currHeight.push_back({height + 1, col});
                    seen[col] = true;
                }
            }

            for (int col = 0; col < n; col++)
            {
                if (seen[col] == false && matrix[row][col] == 1)
                {
                    currHeight.push_back({1, col});
                }
            }

            for (int i = 0; i < currHeight.size(); i++)
            {
                int ht = currHeight[i].first;
                int base = i + 1;
                maxArea = max(maxArea, ht * base);
            }

            prevHeight = currHeight;
        }
        return maxArea;
    }
};
// T.C : O(m* n)
// S.C : O(n)
