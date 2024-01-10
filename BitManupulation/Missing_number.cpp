#include <bits/stdc++.h>
using namespace std;
/**
 * ------------------------------------ Introducion ------------------------------------
 * Title : Missing Number
 * Leetcode No : 268
 * Difficulty : Easy
 * Topic : Array, Bit Manipulation, Math
 * Link : https://leetcode.com/problems/missing-number/description/
 *
 */

/**
 * ------------------------------------ Problem Statement ------------------------------------
 * Given an array nums containing n distinct numbers in the range [0, n],
 * return the only number in the range that is missing from the array.
 *
 * Input: nums = [3,0,1]
 * Output: 2
 * Explanation: n = 3 since there are 3 numbers, so all numbers are in the range [0,3].
 * 2 is the missing number in the range since it does not appear in nums.
 */

/**
 * ------------------------------------ Approach 1 ------------------------------------
 * Time Complexity : O(n)
 * Space Complexity : O(1)
 * Solved By : Math
 */
class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int sum = accumulate(begin(nums), end(nums), 0);

        int n = nums.size();

        // Arithmetic Progression sum formula
        int formulaSum = n * ((n + 1) / 2.0);

        return formulaSum - sum;
    }
};

/**
 * ------------------------------------ Approach 2 ------------------------------------
 * Time Complexity : O(n)
 * Space Complexity : O(1)
 * Solved By : Bit Manipulation
 * [3, 0, 1] = (3 ^ 0 ^ 1) ^ (1 ^ 2 ^ 3) = 2
 */
class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {

        int ans = 0;
        int n = nums.size();
        for (int i = 1; i <= n; i++)
        {
            ans = (ans ^ i) ^ nums[i - 1];
        }
        return ans;
    }
};