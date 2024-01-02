#include <vector>
using namespace std;

/**
 * ----------------------- Introduction ------------------------------------------
 * Title : Find First and Last Position of Element in Sorted Array
 * Leetcode No : 34
 * Difficulty : Medium
 * Topics : Array, Binary Search
 * Link : https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
 *
 */

/**
 * ----------------------- Problem Statement ------------------------------------------
 * Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.
 * If target is not found in the array, return [-1, -1].
 *
 * Input: nums = [5,7,7,8,8,10], target = 8
 * Output: [3,4]
 */

// ----------------------- Approach 1 : Brute Force ---------------------------------
class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int first = -1, last = -1;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == target)
            {
                if (first == -1)
                    first = i;
                last = i;
            }
        }
        return {first, last};
    }
};
// TC : O(n)
// SC : O(1)

// ------------------------ Approach 2 : Optimal Approach (Binary Search) ----------------------------
class Solution
{
public:
    int binarySearch(vector<int> &nums, int target, bool flag)
    {
        int idx = -1;
        int low = 0, high = nums.size() - 1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target)
            {
                idx = mid;
                if (flag == 0) // first occurence
                    high = mid - 1;
                else
                    low = mid + 1; // last occurence
            }
            else if (nums[mid] > target)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return idx;
    }
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int first = binarySearch(nums, target, 0); // first occurence
        int last = binarySearch(nums, target, 1);  // last occurence
        return {first, last};
    }
};
// TC : O(logn)
// SC : O(1)