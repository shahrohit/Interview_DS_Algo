#include <vector>
#include <limits.h>
using namespace std;

// ----------------------- Introduction ------------------------------------------
// Title : Maximum Subarray
// LeetCode No : 53
// Difficulty : Medium
// Topics : Array, Divide Conqure, DP
// Link : https://leetcode.com/problems/maximum-subarray/description/

// ----------------------- Problem Statement --------------------------------------
// Given an integer array nums, find the subarray with the largest sum, and return its sum.
// Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
// Output: 6
// Explanation: The subarray [4,-1,2,1] has the largest sum 6.

// ----------------------- Approach 1 : Brute Force ---------------------------------
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int n = nums.size();
        int maxSum = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            int currSum = 0;
            for (int j = i; j < n; j++)
            {
                currSum += nums[j];
                maxSum = max(maxSum, currSum);
            }
        }
        return maxSum;
    }
};
// TC : O(n * n)
// SC : O(1)

// ------------------------ Approach 2 : kadanes Algo ------------------------------
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {

        int maxSum = INT_MIN;
        int currSum = 0;
        for (auto &num : nums)
        {
            currSum = max(currSum + num, num);
            maxSum = max(maxSum, currSum);
        }
        return maxSum;
    }
};
// TC : O(n)
// SC : O(1)