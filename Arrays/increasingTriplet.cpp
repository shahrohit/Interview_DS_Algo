#include <vector>
#include <limits.h>
using namespace std;

// ----------------------- Introduction ------------------------------------------
// Title : Increasing Triplet Subsequence
// LeetCode No : 334
// Difficulty : Medium
// Topics : Array, Greedy
// Link : https://leetcode.com/problems/increasing-triplet-subsequence/description/

// ----------------------- Problem Statement --------------------------------------

// Given an integer array nums, return true if there exists a triple of indices (i, j, k)
// such that i < j < k and nums[i] < nums[j] < nums[k]. If no such indices exists, return false.

// Input: nums = [2,1,5,0,4,6]
// Output: true
// Explanation: The triplet (3, 4, 5) is valid because nums[3] == 0 < nums[4] == 4 < nums[5] == 6.

// ------------------------------ Approach 1 ----------------------------------------
class Solution
{
public:
    bool increasingTriplet(vector<int> &nums)
    {

        int a = INT_MAX, b = INT_MAX;
        for (auto &num : nums)
        {

            if (num <= a)
                a = num;

            else if (num <= b)
                b = num;

            else
                return true;
        }
        return false;
    }
};
// T.C : O(n)
// S.C : O(1)