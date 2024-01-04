#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

/**
 * ----------------------- Introduction ------------------------------------------
 * Title : Diagonal Traverse II
 * LeetCode No : 1424
 * Difficulty : Medium
 * Topics : Array, Matrix, HashMap
 * Link : https://leetcode.com/problems/diagonal-traverse-ii/
 *
 * */

/**
 * ----------------------- Problem Statement --------------------------------------
 * Given a list of lists of integers, nums, return all elements of nums in diagonal order as shown in the below images.
 * Input: nums = [[1,2,3],[4,5,6],[7,8,9]]
 * Output: [1,4,2,7,5,3,8,6,9]
 *
 * Input: nums = [[1,2,3,4,5],[6,7],[8],[9,10,11],[12,13,14,15,16]]
 * Output: [1,6,2,8,7,3,9,4,12,10,5,13,11,14,15,16]
 *
 * */

// ----------------------- Approach 1  ---------------------------------

class Solution
{
public:
    vector<int> findDiagonalOrder(vector<vector<int>> &nums)
    {
        unordered_map<int, vector<int>> groups;

        for (int row = nums.size() - 1; row >= 0; row--)
        {
            for (int col = 0; col < nums[row].size(); col++)
            {
                int diagonal = row + col;
                groups[diagonal].push_back(nums[row][col]);
            }
        }

        vector<int> result;
        int diagonal = 0;

        while (groups.find(diagonal) != groups.end())
        {
            vector<int> temp = groups[diagonal];
            result.insert(end(result), begin(temp), end(temp));
            diagonal++;
        }

        return result;
    }
};
// Time Complexity : O(m * n + (m + n) * m)
// Space Complexity : O(m * n)