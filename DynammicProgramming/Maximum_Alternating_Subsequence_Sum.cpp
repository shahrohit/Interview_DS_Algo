#include <bits/stdc++.h>
using namespace std;
/**
 * ------------------------------------ Introducion ------------------------------------
 * Title : Maximum Alternating Subsequence Sum
 * Leetcode No : 1911
 * Difficulty : Medium
 * Topic : Array, Dynamic Programming
 * Link : https://leetcode.com/problems/maximum-alternating-subsequence-sum/
 *
 */

/**
 * ------------------------------------ Problem Statement ------------------------------------
 * Given a 0-indexed array nums of integers, return the maximum alternating sum of any subsequence of nums (after reindexing the elements of the subsequence).
 * A subsequence of an array is a new array formed by deleting some elements (possibly zero) without changing the remaining elements' relative order.
 * For example, [2,7,4] is a subsequence of [4,2,3,7,2,1,4], while [2,4,2] is not.
 * A alternating subsequence is a subsequence where the elements are in alternating order, i.e. they are in the form [a,b,a,b] or [b,a,b,a] where a and b are
 * elements of the subsequence.
 *
 * Example 1:
 * Input: nums = [4,2,5,3]
 * Output: 7
 * Explanation: It is optimal to choose the subsequence [4,2,5,3] with alternating sum (4 + 5 + 3) - (2 + 3) = 7.
 *
 */

// ------------------------------------ Recursion ------------------------------------
class Solution
{
public:
    long long solve(vector<int> &nums, int idx, bool evenIdx)
    {
        if (idx >= nums.size())
            return 0;

        // take the number
        long long take = (evenIdx ? nums[idx] : -nums[idx]);
        take += solve(nums, idx + 1, !evenIdx);

        // skip the number
        long long skip = solve(nums, idx + 1, evenIdx);

        return max(take, skip);
    }
    long long maxAlternatingSum(vector<int> &nums)
    {
        return solve(nums, 0, true);
    }
};

// Time Complexity : O(2^n)
// Space Complexity : O(n)

// ------------------------------------ Recursion + Memoization ------------------------------------
class Solution
{
public:
    long long solve(vector<int> &nums, int idx, bool flag, vector<vector<long long>> &dp)
    {
        if (idx >= nums.size())
            return 0;
        if (dp[idx][flag] != -1)
            return dp[idx][flag];

        long long take = (flag ? nums[idx] : -nums[idx]);
        take += solve(nums, idx + 1, !flag, dp);

        long long skip = solve(nums, idx + 1, flag, dp);

        return dp[idx][flag] = max(take, skip);
    }
    long long maxAlternatingSum(vector<int> &nums)
    {
        vector<vector<long long>> dp(nums.size(), vector<long long>(2, -1));
        return solve(nums, 0, true, dp);
    }
};

// Time Complexity : O(n)
// Space Complexity : O(n)

// ------------------------------------ Bottom Up DP ------------------------------------
class Soltuion
{
    long long maxAlternatingSum(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<long long>> dp(n + 1, vector<long long>(2, 0));

        for (int i = 1; i <= n; i++)
        {
            // make even length
            long long take = dp[i - 1][1] - nums[i - 1];
            long long skip = dp[i - 1][0];

            dp[i][0] = max(take, skip); // max of even length

            // make odd length
            take = dp[i - 1][0] + nums[i - 1];
            skip = dp[i - 1][1];

            dp[i][1] = max(take, skip); // max of odd length
        }

        return max(dp[n][0], dp[n][1]);
    }
};

// Time Complexity : O(n)
// Space Complexity : O(n)