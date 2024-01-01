#include <vector>
using namespace std;

// ----------------------- Introduction ------------------------------------------
// Title : Find the Duplicate Number
// LeetCode No : 287
// Difficulty : Medium
// Topics : Array
// Link : https://leetcode.com/problems/find-the-duplicate-number/description/

// ----------------------- Problem Statement --------------------------------------

// Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.
// There is only one repeated number in nums, return this repeated number.
// You must solve the problem without modifying the array nums and uses only constant extra space.

// Input: nums = [1,3,4,2,2]
// Output: 2

// ------------------------------ Approach 1 : Slow and Fast Pointer ---------------------------------
class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {

        int slow = 0, fast = 0;
        do
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);

        slow = 0;
        while (slow != fast)
        {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};
// T.C : O(n)
// S.C : O(1)