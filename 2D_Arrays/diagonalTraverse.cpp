#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

// ----------------------- Introduction ------------------------------------------
// Title : Diagonal Traverse
// LeetCode No : 498
// Difficulty : Medium
// Topics : Array, Matrix, Sorting, HashMap
// Link : https://leetcode.com/problems/diagonal-traverse/description/

// ----------------------- Problem Statement --------------------------------------
// Given an m x n matrix mat, return an array of all the elements of the array in a diagonal order
// Input: mat = [[1,2,3],[4,5,6],[7,8,9]]
// Output: [1,2,4,7,5,3,6,8,9]

// ----------------------- Approach 1  ---------------------------------

class Solution
{
public:
    vector<int> findDiagonalOrder(vector<vector<int>> &mat)
    {
        unordered_map<int, vector<int>> map;
        int m = mat.size();
        int n = mat[0].size();

        for (int i = 0; i < m; i++) // -> m
        {
            for (int j = 0; j < n; j++) // -> n
            {
                int key = i + j;
                map[key].push_back(mat[i][j]);
            }
        }
        vector<int> ans;
        int size = map.size();
        for (int i = 0; i < size; i++)
        {
            if (i % 2 == 0)
                reverse(map[i].begin(), map[i].end());           // -> O(m)
            ans.insert(ans.end(), map[i].begin(), map[i].end()); // O(n)
        }

        return ans;
    }
};

// T.C : O(m * n + (m + n) * m)
// S.C : O(m * n)