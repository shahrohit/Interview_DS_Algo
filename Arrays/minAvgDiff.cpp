#include <vector>
#include <cmath>
using namespace std;

// ----------------------- Introduction ------------------------------------------
// Title : Minimum Average Difference
// LeetCode No : 2256
// Difficulty : Medium
// Topics : Array, Prefix Sum
// Link : https://leetcode.com/problems/minimum-average-difference/description/

// ----------------------- Problem Statement --------------------------------------

// You are given a 0-indexed integer array nums of length n.
// The average difference of the index i is the absolute difference between the average of the first i + 1 elements of nums
// and the average of the last n - i - 1 elements. Both averages should be rounded down to the nearest integer.
// Return the index with the minimum average difference. If there are multiple such indices, return the smallest one.
// Note:
// 1. The absolute difference of two numbers is the absolute value of their difference.
// 2. The average of n elements is the sum of the n elements divided (integer division) by n.
// 3. The average of 0 elements is considered to be 0.

// Input: nums = [2,5,3,9,5,3]
// Output: 3

// ------------------------ Approach 1 ------------------------------
class Solution
{
public:
    int minimumAverageDifference(vector<int> &nums)
    {
        int n = nums.size();

        long leftSum = 0, rightSum = 0;
        for (int i = 0; i < n; i++)
            rightSum += nums[i];

        int minAvg = INT_MAX;
        int minAvgIdx = -1;
        for (int i = 0; i < n; i++)
        {

            leftSum += nums[i];
            rightSum -= nums[i];

            int leftAvg = leftSum / (i + 1);
            int rightAvg = (i + 1 == n) ? 0 : rightSum / (n - i - 1);
            int currAvg = abs(leftAvg - rightAvg);

            if (currAvg < minAvg)
            {
                minAvg = currAvg;
                minAvgIdx = i;
            }
        }

        return minAvgIdx;
    }
};
// TC : O(n)
// SC : O(1)