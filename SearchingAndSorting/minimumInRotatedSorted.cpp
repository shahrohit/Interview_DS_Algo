#include <vector>
using namespace std;

/**
 * ----------------------- Introduction ------------------------------------------
 * Title : Find Minimum in Rotated Sorted Array
 * Leetcode No : 153
 * Difficulty : Medium
 * Topics : Array, Binary Search
 * Link : https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
 *
 */

/**
 * ----------------------- Problem Statement ------------------------------------------
 * Suppose an array of length n sorted in ascending order is rotated between 1 and n times.
 * For example, the array nums = [0,1,2,4,5,6,7] might become:
 *     [4,5,6,7,0,1,2] if it was rotated 4 times.
 *    [0,1,2,4,5,6,7] if it was rotated 7 times.
 * Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in
 * the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].
 * Given the sorted rotated array nums of unique elements, return the minimum element of this array.
 * You must write an algorithm that runs in O(log n) time.
 *
 * Input: nums = [3,4,5,1,2]
 * Output: 1
 * Explanation: The original array was [1,2,3,4,5] rotated 3 times.
 *
 */

// ----------------------- Approach 1 : Brute Force ---------------------------------
class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int minValue = nums[0];
        for (int &num : nums)
        {
            minValue = min(minValue, num);
        }
        return minValue;
    }
};
// TC : O(n)
// SC : O(1)

// ------------------------ Approach 2 : Optimal Approach (Binary Search) ----------------------------

class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int low = 0, high = nums.size() - 1;
        while (low < high)
        {
            int mid = low + (high - low) / 2;
            if (nums[mid] > nums[high])
                low = mid + 1;
            else
                high = mid;
        }
        return nums[low];
    }
};
// TC : O(logn)
// SC : O(1)