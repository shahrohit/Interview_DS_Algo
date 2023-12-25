#include <vector>
#include <unordered_map>
using namespace std;

// ----------------------- Introduction ------------------------------------------
// Title : Two Sum
// LeetCode No : 1
// Difficulty : Easy
// Topics : Array, Hash Table
// Link : https://leetcode.com/problems/two-sum/description/

// ----------------------- Problem Statement --------------------------------------
// Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
// You may assume that each input would have exactly one solution,
// and you may not use the same element twice.
//   You can return the answer in any order.

// ----------------------- Approach 1 : Brute Force ---------------------------------
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        for (int i = 0; i < nums.size(); i++)
        {

            for (int j = i + 1; j < nums.size(); j++)
            {
                if (nums[i] + nums[j] == target)
                    return {i, j};
            }
        }
        return {};
    }
};
// TC : O(n*n)
// SC : O(1)

// ------------------------ Approach 2 : Optimal Approach ------------------------------
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        int n = nums.size();
        unordered_map<int, int> map;
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            int rem = target - nums[i];
            if (map.find(rem) != map.end())
                return {map[rem], i};
            else
                map[nums[i]] = i;
        }
        return {};
    }
};
// TC : O(n)
// SC : O(n)