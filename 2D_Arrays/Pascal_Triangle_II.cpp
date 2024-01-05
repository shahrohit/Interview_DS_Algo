#include <vector>
using namespace std;

/**
 * ----------------------- Introduction ------------------------------------------
 * Title : Pascal's Triangle II
 * LeetCode No : 119
 * Difficulty : Easy
 * Topics : Array, Math, Matrix
 * Link : https://leetcode.com/problems/pascals-triangle-ii/description/
 */

/**
 *  ----------------------- Problem Statement --------------------------------------
 *
 * Given an integer rowIndex, return the rowIndexth (0-indexed) row of the Pascal's triangle.
 * In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:
 *
 * Input: rowIndex = 3
 * Output: [1,3,3,1]
 *
 */

// ----------------------- Approach 1 : ---------------------------------

class Solution
{
public:
    vector<int> getRow(int rowIndex)
    {

        vector<vector<int>> pascal;
        for (int i = 0; i <= rowIndex; i++)
        {
            vector<int> arr(i + 1);
            arr[0] = arr[i] = 1;
            for (int j = 1; j < i; j++)
            {
                arr[j] = pascal[i - 1][j] + pascal[i - 1][j - 1];
            }
            pascal.push_back(arr);
        }
        return pascal[rowIndex];
    }
};

// Time Complexity : O(n * n) where n is the rowIndex
// Space Complexity : O(n * n)

// ----------------------- Approach 2 : ---------------------------------
class Solution
{
public:
    vector<int> getRow(int rowIndex)
    {
        vector<int> prev;
        for (int i = 0; i <= rowIndex; i++)
        {
            vector<int> curr(i + 1);
            curr[0] = curr[i] = 1;
            for (int j = 1; j < i; j++)
            {
                curr[j] = prev[j] + prev[j - 1];
            }
            prev = curr;
        }
        return prev;
    }
};
// Time Complexity : O(n * n) where n is the rowIndex
// Space Complexity : O(n)

// ----------------------- Approach 3 : ---------------------------------
class Solution
{
public:
    vector<int> getRow(int rowIndex)
    {

        vector<int> ans;

        // C(n, r + 1) = C(n,r) * [(n - r)/ (r + 1)]

        int prev = 1;
        for (int r = 0; r < rowIndex; r++)
        {
            ans.push_back(prev);
            prev = prev * ((rowIndex - r) / (r + 1));
        }
        ans.push_back(1);
        return ans;
    }
};
// Time Complexity : O(n)
// Space Complexity : O(1)