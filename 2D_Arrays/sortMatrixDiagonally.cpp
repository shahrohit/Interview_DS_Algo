#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

// ----------------------- Introduction ------------------------------------------
// Title : Sort the Matrix Diagonally
// LeetCode No : 1329
// Difficulty : Medium
// Topics : Array, Matrix, Sorting, HashMap
// Link : https://leetcode.com/problems/sort-the-matrix-diagonally/

// ----------------------- Problem Statement --------------------------------------
// Given an m x n matrix mat of integers, sort each matrix diagonal in ascending order and
// return the resulting matrix.
// Input: matrix = [
// [3,3,1,1],
// [2,2,1,2],
// [1,1,1,2]]

// Output: [
// [1,1,1,1],
// [1,2,2,2],
// [1,2,3,3]]

// ----------------------- Approach 1  ---------------------------------

class Solution
{
public:
    vector<vector<int>> diagonalSort(vector<vector<int>> &mat)
    {
        unordered_map<int, vector<int>> map;
        int m = mat.size();
        int n = mat[0].size();

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int key = j - i; // group the diagonal
                map[key].push_back(mat[i][j]);
            }
        }
        // sort
        for (auto &[key, vec] : map) // -> O(m + n)
        {
            sort(vec.begin(), vec.end()); // m * log(m)
        }

        vector<vector<int>> result(m, vector<int>(n));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int key = j - i;
                int vecIdx = min(i, j);
                result[i][j] = map[key][vecIdx];
            }
        }
        return result;
    }
};

// T.C : O(m * n + (m+n) * mlog(m))
// S.C : O(m * n)
