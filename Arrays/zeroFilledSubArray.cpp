#include <vector>
using namespace std;

// ----------------------- Introduction ------------------------------------------
// Title : Number of Zero-Filled Subarrays
// LeetCode No : 2358
// Difficulty : Medium
// Topics : Array, Math
// Link : https://leetcode.com/problems/number-of-zero-filled-subarrays/description/

// ----------------------- Problem Statement --------------------------------------

// Given an integer array nums, return the number of subarrays filled with 0.
// A subarray is a contiguous non-empty sequence of elements within an array.
// Input: nums = [0,0,0,2,0,0]
// Output: 9
// Explanation:
// There are 5 occurrences of [0] as a subarray.
// There are 3 occurrences of [0,0] as a subarray.
// There is 1 occurrence of [0,0,0] as a subarray.
// There is no occurrence of a subarray with a size more than 3 filled with 0. Therefore, we return 9.

// ------------------------------------ Approach 1 ----------------------------------------------
class Solution
{
public:
    long long zeroFilledSubarray(vector<int> &nums)
    {

        long long ans = 0;
        int term = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
                term++;
            else
                term = 0;

            ans += term;
        }

        return ans;
    }
};

// T.C : O(n)
// S.C : O(1)