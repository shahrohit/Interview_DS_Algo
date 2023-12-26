#include <algorithm>
#include <vector>
using namespace std;

// ----------------------- Introduction ------------------------------------------
// Title : Sort Colors
// LeetCode No : 75
// Difficulty : Medium
// Topics : Array, Sorting, Two Pointers
// Link : https://leetcode.com/problems/sort-colors/description/

// ----------------------- Problem Statement --------------------------------------
// Given an array nums with n objects colored red, white, or blue, sort them in-place
// so that objects of the same color are adjacent, with the colors in the order red, white, and blue.
// We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

// Input: nums = [2,0,2,1,1,0]
// Output: [0,0,1,1,2,2]

// ----------------------- Approach 1 : Brute Force ---------------------------------
class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        sort(begin(nums), end(nums));
    }
};
// TC : O(n*log(n))
// SC : O(1)

// ------------------------ Approach 2 : Counting ------------------------------
class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int colors[3] = {0, 0, 0}; // [0, 0, 0] => [red, white, blue];
        // count the colors
        for (auto &num : nums)
        {
            colors[num]++;
        }
        // update the nums array
        int idx = 0;
        for (int col = 0; col < 3; col++)
        {
            for (int i = 0; i < colors[col]; i++)
            {
                nums[idx++] = col;
            }
        }
    }
};
// TC : O(n)
// SC : O(1)

// ------------------------ Approach 3 : Dutch National Flag Algorithm ------------------------------
class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int n = nums.size();
        int redIdx = 0;
        int blueIdx = n - 1;
        int numsIdx = 0;
        while (numsIdx <= blueIdx)

            if (nums[numsIdx] == 2)
                swap(nums[numsIdx], nums[blueIdx--]);

            else if (nums[numsIdx] == 0)
                swap(nums[numsIdx++], nums[redIdx++]);

            else
                numsIdx++;
    }
};
// T.C : O(n)
// S.C : O(1)