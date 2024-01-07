#include <vector>
#include <algorithm>
using namespace std;

// ----------------------- Introduction ------------------------------------------
// Title : 3 Sum
// LeetCode No : 15
// Difficulty : Medium
// Topics : Array, Two Pointers, Sorting
// Link : https://leetcode.com/problems/3sum/

// ----------------------- Problem Statement --------------------------------------
// Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]]
// such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
// Notice that the solution set must not contain duplicate triplets.
// Input: nums = [-1,0,1,2,-1,-4]
// Output: [[-1,-1,2],[-1,0,1]]
// Explanation:
// nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
// nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
// nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
// The distinct triplets are [-1,0,1] and [-1,-1,2].
// Notice that the order of the output and the order of the triplets does not matter.

// ------------------------ Approach 1 : Sorting & Two Pointers  ------------------------------
class Solution
{
public:
    vector<vector<int>> ans;

    // helper fuction to find the two sum
    void twoSum(vector<int> &nums, int target, int leftIdx, int rightIdx)
    {
        while (leftIdx < rightIdx)
        {

            int val = nums[leftIdx] + nums[rightIdx];
            if (val > target)
                rightIdx--;
            else if (val < target)
                leftIdx++;
            else
            {
                // duplicates in the left side
                while (leftIdx < rightIdx && nums[leftIdx] == nums[leftIdx + 1])
                    leftIdx++;
                // duplicates in right side
                while (leftIdx < rightIdx && nums[rightIdx] == nums[rightIdx - 1])
                    rightIdx--;

                ans.push_back({-target, nums[leftIdx++], nums[rightIdx--]});
            }
        }
    }

    // 3 Sum function
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        int n = nums.size();
        // sort the array - as we have to find the nums not there index
        sort(nums.begin(), nums.end());

        for (int i = 0; i <= n - 3; i++)
        {
            // since element can be duplicates
            // so find only one three sum
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            // nums[i] + nums[j] + nums[k] = 0
            // num[j] + nums[k] = -nums[i]
            // i.e. find the two numbers that sum gives the negetive of nums[i]
            // Apply Two sum in the sorted array
            int target = -nums[i];
            twoSum(nums, target, i + 1, n - 1);
        }
        return ans;
    }
};
// TC : O(n*n + nlog(n))
// SC : O(1)