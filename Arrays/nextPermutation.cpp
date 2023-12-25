#include <vector>
#include <algorithm>
using namespace std;

// ----------------------- Introduction ------------------------------------------
// Title : Next Permutation
// LeetCode No : 31
// Difficulty : Medium
// Topics : Array, Two Pointers
// Link : https://leetcode.com/problems/next-permutation/description/

// ----------------------- Problem Statement --------------------------------------
// Given an array of integers nums, find the next permutation of nums.
// Input: nums = [1,2,3]
// Output: [1,3,2]

// --------------------------- Approach 1   ----------------------------------------
// similar to find the next greater element
class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {

        int n = nums.size();

        int idx = n - 2;
        while (idx >= 0 && nums[idx] >= nums[idx + 1])
            idx--;

        if (idx < 0)
        {
            reverse(begin(nums), end(nums));
            return;
        }

        // next greater
        int k = n - 1;
        while (nums[idx] >= nums[k])
            k--;

        swap(nums[idx], nums[k]);
        reverse(nums.begin() + idx + 1, nums.end());
    }
};
// TC : O(n)
// SC : O(1)