#include <vector>
#include <numeric>
#include <limits.h>
using namespace std;

// ----------------------- Introduction ------------------------------------------
// Title : Maximum Sum Circular Subarray
// LeetCode No : 918
// Difficulty : Medium
// Topics : Array
// Link : https://leetcode.com/problems/maximum-sum-circular-subarray/description/

// ----------------------- Problem Statement --------------------------------------
// Given a circular integer array nums of length n,
// return the maximum possible sum of a non-empty subarray of nums.
// Input: nums = [5,-3,5]
// Output: 10
// Explanation: Subarray [5,5] has maximum sum 5 + 5 = 10.

// ----------------------- Approach 1 : Brute Force ---------------------------------
class Solution
{
public:
    int maxSubarraySumCircular(vector<int> &nums)
    {

        int n = nums.size();
        int maxSum = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            int j = i;
            int currSum = 0;
            do
            {
                currSum += nums[j];
                maxSum = max(maxSum, currSum);
                if (currSum < 0)
                    currSum = 0;

                j = (j + 1) % n;
            } while (j % n != i);
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
    int kadanesMax(vector<int> &nums)
    {
        int n = nums.size();
        int maxSum = nums[0], currSum = nums[0];
        for (int i = 1; i < n; i++)
        {
            currSum = max(currSum + nums[i], nums[i]);
            maxSum = max(maxSum, currSum);
        }
        return maxSum;
    }
    int kadanesMin(vector<int> &nums)
    {
        int n = nums.size();
        int minSum = nums[0], currSum = nums[0];
        for (int i = 1; i < n; i++)
        {
            currSum = min(currSum + nums[i], nums[i]);
            minSum = min(minSum, currSum);
        }
        return minSum;
    }
    int maxSubarraySumCircular(vector<int> &nums)
    {
        // total sum of the array
        int totalSum = accumulate(begin(nums), end(nums), 0);
        // max Sum of sub array
        int maxSum = kadanesMax(nums);
        // min sum of sub array
        int minSum = kadanesMin(nums);
        // max Sum in Circular array => total sum - min sum of sub array
        int circularSum = totalSum - minSum;

        if (circularSum == 0) // for cases like [-1,-2,-3]
            return maxSum;

        return max(maxSum, circularSum);
    }
};
// TC : O(n)
// SC : O(1)