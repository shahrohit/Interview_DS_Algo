#include <vector>
#include <unordered_map>
using namespace std;

// ----------------------- Introduction ------------------------------------------
// Title : Two Sum II - Input Array Is Sorted
// LeetCode No : 167
// Difficulty : Medium
// Topics : Array, Two Pointers
// Link : https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/

// ----------------------- Problem Statement --------------------------------------
// Given a 1-indexed array of integers numbers that is already sorted in non-decreasing order,
// find two numbers such that they add up to a specific target number.
// and you may not use the same element twice.
// You can return the answer in any order.

// ------------------------ Approach 1 : Two Pointers  ------------------------------
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        int n = nums.size();
        int left = 0, right = 0;
        while (left < right)
        {
            int value = nums[left] + nums[right];

            if (value == target)
                return {left, right};

            if (value > target)
                right--;
            else
                left++;
        }

        return {};
    }
};
// TC : O(n)
// SC : O(1)