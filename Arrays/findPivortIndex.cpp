#include <vector>
#include <numeric>
using namespace std;

// ----------------------- Introduction ------------------------------------------
// Title : Find Pivot Index
// LeetCode No : 724
// Difficulty : Easy
// Topics : Array, Prefix Sum
// Link : https://leetcode.com/problems/find-pivot-index/description/

// ----------------------- Problem Statement --------------------------------------

// Given an array of integers nums, calculate the pivot index of this array.
// The pivot index is the index where the sum of all the numbers strictly to the left of the index is
// equal to the sum of all the numbers strictly to the index's right.
// If the index is on the left edge of the array, then the left sum is 0.
// Return the leftmost pivot index. If no such index exists, return -1.

// Input: nums = [1,7,3,6,5,6]
// Output: 3
// Explanation:
// The pivot index is 3.
// Left sum = nums[0] + nums[1] + nums[2] = 1 + 7 + 3 = 11
// Right sum = nums[4] + nums[5] = 5 + 6 = 11

// ----------------------- Approach 1 ---------------------------------
class Solution
{
public:
    int pivotIndex(vector<int> &nums)
    {
        int leftSum = 0;
        int rightSum = accumulate(begin(nums), end(nums), 0);

        for (int i = 0; i < nums.size(); i++)
        {
            rightSum -= nums[i];
            if (leftSum == rightSum)
                return i;
            leftSum += nums[i];
        }
        return -1;
    }
};
// T.C : O(n)
// S.C : O(1)