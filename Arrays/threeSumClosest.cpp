#include <vector>
#include <algorithm>
using namespace std;

// ----------------------- Introduction ------------------------------------------
// Title : 3 Sum Closest
// LeetCode No : 16
// Difficulty : Medium
// Topics : Array, Two Pointers, Sorting
// Link : https://leetcode.com/problems/3sum-closest/description/

// ----------------------- Problem Statement --------------------------------------
// Given an integer array nums of length n and an integer target, find three integers in nums such that the sum is closest to target.
// Return the sum of the three integers.
// You may assume that each input would have exactly one solution.

// ------------------------ Approach 1 : Sorting & Two Pointers  ------------------------------
class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {

        int n = nums.size();
        // sorting - as we have to find the elements not index
        sort(begin(nums), end(nums));

        int closestSum = INT_MAX;
        for (int k = 0; k <= n - 3; k++)
        {

            int i = k + 1, j = n - 1;
            while (i < j)
            {
                int currSum = nums[i] + nums[j] + nums[k];
                // check for closest sum
                if (closestSum == INT_MAX || abs(target - currSum) < abs(target - closestSum))
                    closestSum = currSum;

                if (currSum > target)
                    j--;
                else if (currSum < target)
                    i++;
                else
                    return closestSum;
            }
        }
        return closestSum;
    }
};
// TC : O(n*n + nlog(n))
// SC : O(1)