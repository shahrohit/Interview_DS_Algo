#include <vector>
#include <algorithm>
using namespace std;

// ----------------------- Introduction ------------------------------------------
// Title : Pascal's Triangle
// LeetCode No : 118
// Difficulty : Easy
// Topics : Array, Math, Matrix
// Link : https://leetcode.com/problems/pascals-triangle/description/

// ----------------------- Problem Statement --------------------------------------
// Given an integer numRows, return the first numRows of Pascal's triangle.
// Input: numRows = 5
// Output:
// [
//  [1],
//  [1,1],
//  [1,2,1],
//  [1,3,3,1],
//  [1,4,6,4,1]
// ]

// ----------------------- Approach 1 : ---------------------------------

class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> matrix(numRows);

        for (int i = 0; i < numRows; i++)
        {

            vector<int> rowArray(i + 1);
            // first and last element is each row is always one
            rowArray[0] = rowArray[i] = 1;
            // assigning value to the array except in first and last index
            for (int j = 1; j < i; j++)
            {
                rowArray[j] = matrix[i - 1][j] + matrix[i - 1][j - 1];
            }
            matrix[i] = rowArray;
        }
        return matrix;
    }
};

// T.C : O(n * n)
// S.C : O(1)