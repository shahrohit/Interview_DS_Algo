#include <vector>
#include <unordered_map>
using namespace std;

// ----------------------- Introduction ------------------------------------------
// Title : Contains Duplicate II
// LeetCode No : 219
// Difficulty : Easy
// Topics : Array, Hash Table, Sliding Window
// Link : https://leetcode.com/problems/contains-duplicate-ii/description/

// ----------------------- Problem Statement --------------------------------------

// Given an integer array nums and an integer k, return true if there are
// two distinct indices i and j in the array such that nums[i] == nums[j] and abs(i - j) <= k.

// Input: nums = [1,0,1,1], k = 1
// Output: true
// Explanation : nums[2] == nums[3] and abs(0-1) <= 1
// ------------------------------ Approach 1 ----------------------------------------
class Solution
{
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++)
        {

            if (map.find(nums[i]) != map.end() && (i - map[nums[i]] <= k))
            {
                return true;
            }

            map[nums[i]] = i;
        }
        return false;
    }
};
// T.C : O(n))
// S.C : O(n)