#include <vector>
#include <algorithm>
using namespace std;

// ----------------------- Introduction ------------------------------------------
// Title : Largest Perimeter Triangle
// LeetCode No : 976
// Difficulty : Easy
// Topics : Array, Greedy, Sorting
// Link : https://leetcode.com/problems/largest-perimeter-triangle/description/

// ----------------------- Problem Statement --------------------------------------

// Given an integer array nums, return the largest perimeter of a triangle with a non-zero area,
// formed from three of these lengths. If it is impossible to form any triangle of a non-zero area, return 0.

// Input: nums = [2,1,2]
// Output: 5
// Explanation: You can form a triangle with three side lengths: 1, 2, and 2.

// ------------------------------ Approach 1 ----------------------------------------
class Solution
{
public:
    int largestPerimeter(vector<int> &nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        for (int i = n - 3; i >= 0; i--)
        {
            if (nums[i] + nums[i + 1] > nums[i + 2])
            {
                return nums[i] + nums[i + 1] + nums[i + 2];
            }
        }
        return 0;
    }
};
// T.C : O(nlog(n))
// S.C : O(1)