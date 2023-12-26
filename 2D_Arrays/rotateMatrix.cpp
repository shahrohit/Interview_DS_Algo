#include <vector>
#include <algorithm>
using namespace std;

// ----------------------- Introduction ------------------------------------------
// Title : Rotate Image
// LeetCode No : 48
// Difficulty : Medium
// Topics : Array, Math, Matrix
// Link : https://leetcode.com/problems/rotate-image/

// ----------------------- Problem Statement --------------------------------------
// You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).
// Input: matrix = [
// [1,2,3],
// [4,5,6],
// [7,8,9]]

// Output: [
// [7,4,1],
// [8,5,2],
// [9,6,3]]

// ----------------------- Approach 1 : Transopse & reverse ---------------------------------
// 1. transpose the matrix
// 2. reverse each row

class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        int n = matrix.size();

        for (int i = 0; i < n; i++)
        {
            // transpose
            for (int j = i + 1; j < n; j++)
                swap(matrix[i][j], matrix[j][i]);

            // reverse
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};

// T.C : O(n*n)
// S.C : O(1)