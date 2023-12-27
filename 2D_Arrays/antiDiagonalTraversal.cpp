#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

// ----------------------- Introduction ------------------------------------------
// Title : Anti Diagonal Traversal of Matrix
// Platform : GFG
// Difficulty : Medium
// Topics : Array, Matrix, HashMap
// Link : https://www.geeksforgeeks.org/problems/print-diagonally1623/1

// ----------------------- Problem Statement --------------------------------------
// Give a N*N square matrix, return an array of its anti-diagonals in top-leftmost to bottom-rightmost order.
// In an element of a anti-diagonal (i, j), surrounding elements will be (i+1, j-1) and (i-1, j+1).
// Look at the examples for more clarity.

// N = 3
// matrix[][] = 3 2 3
//              4 5 1
//              7 8 9
// Output:
// 3 2 4 3 5 7 1 8 9

// ----------------------- Approach 1 : Hash map  ---------------------------------
class Solution
{
public:
    vector<int> antiDiagonalPattern(vector<vector<int>> matrix)
    {
        // Code here
        int n = matrix.size();

        unordered_map<int, vector<int>> map;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int key = i + j;
                map[key].push_back(matrix[i][j]);
            }
        }
        int size = map.size();
        vector<int> result;
        for (int i = 0; i < size; i++)
        {
            result.insert(result.end(), map[i].begin(), map[i].end());
        }
        return result;
    }
};
// T.C => O(n * n)
// S.C => O(n * n)

// ----------------------- Approach 2 : traversal  ---------------------------------
class Solution
{
public:
    vector<int> antiDiagonalPattern(vector<vector<int>> matrix)
    {
        // Code here
        int n = matrix.size();
        vector<int> result;
        // upper half - for the 0th row
        for (int j = 0; j < n; j++)
        {
            int row = 0;
            int col = j;
            while (row < n && col >= 0)
            {
                result.push_back(matrix[row][col]);
                row++;
                col--;
            }
        }
        // lower half - for the (1th to n - 1 th ) row
        for (int i = 1; i < n; i++)
        {
            int row = i;
            int col = n - 1;
            while (row < n && col >= 0)
            {
                result.push_back(matrix[row][col]);
                row++;
                col--;
            }
        }
        return result;
    }
};
// T.C => O(n * n)
// S.C => O(1)