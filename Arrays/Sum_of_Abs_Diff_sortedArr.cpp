#include <vector>
#include <numeric>
using namespace std;

/**
 * ------------------------------------ Introducion ------------------------------------
 * Title : Sum of Absolute Differences in a Sorted Array
 * LeetCode No : 1685
 * Diffulty : Medium
 * Topic : Array, Prefix Sum
 * Link : https://leetcode.com/problems/sum-of-absolute-differences-in-a-sorted-array/
 *
 */

/**
 * ------------------------------------ Problem Statement ------------------------------------
 * You are given an integer array nums sorted in non-decreasing order.
 * Build and return an integer array result with the same length as nums
 * such that result[i] is equal to the summation of absolute differences between
 * nums[i] and all the other elements in the array.
 * In other words, result[i] is equal to sum(|nums[i]-nums[j]|) where 0 <= j < nums.length and j != i (0-indexed).
 *
 * Input: nums = [2,3,5]
 * Output: [4,3,5]
 * Explanation: Assuming the arrays are 0-indexed, then
 * result[0] = |2-2| + |2-3| + |2-5| = 0 + 1 + 3 = 4,
 * result[1] = |3-2| + |3-3| + |3-5| = 1 + 0 + 2 = 3,
 * result[2] = |5-2| + |5-3| + |5-5| = 3 + 2 + 0 = 5.
 *
 */

// ------------------------------------ Approach 1 ------------------------------------
class Solution
{
public:
    vector<int> getSumAbsoluteDifferences(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> result(n);
        vector<int> prefix(n);
        vector<int> suffix(n);

        prefix[0] = suffix[n - 1] = 0;
        for (int i = 1; i < n; i++)
            prefix[i] = nums[i - 1] + prefix[i - 1];

        for (int i = n - 2; i >= 0; i--)
            suffix[i] = nums[i + 1] + suffix[i + 1];

        long long sum = 0;
        for (int i = 0; i < n; i++)
        {
            int leftSum = (nums[i] * i - prefix[i]);
            int rightSum = (suffix[i] - nums[i] * (n - i - 1));
            result[i] = leftSum + rightSum;
        }
        return result;
    }
};

// Time Complexity : O(n)
// Space Complexity : O(n)

// ------------------------------------ Approach 2 ------------------------------------
class Solution
{
public:
    vector<int> getSumAbsoluteDifferences(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> result(n);

        int prefixSum = 0;
        int SuffixSum = accumulate(nums.begin(), nums.end(), 0);

        for (int i = 0; i < n; i++)
        {
            SuffixSum -= nums[i];

            int leftSum = nums[i] * i - prefixSum;
            int rightSum = SuffixSum - nums[i] * (n - i - 1);
            result[i] = leftSum + rightSum;

            prefixSum += nums[i];
        }
        return result;
    }
};

// Time Complexity : O(n)
// Space Complexity : O(1)