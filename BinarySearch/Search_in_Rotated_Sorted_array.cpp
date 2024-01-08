#include <vector>
using namespace std;

/**
 * ------------------------------------ Introducion ------------------------------------
 * Title : Search in Rotated Sorted Array
 * LeetCode No : 33
 * Difficulty : Medium
 * Topic : Binary Search
 * Link : https://leetcode.com/problems/search-in-rotated-sorted-array/
 *
 */

/**
 * ------------------------------------ Problem Statement ------------------------------------
 * Find the index of the target element in the given sorted and rotated array.
 * If not found, return -1.
 *
 * Example 1:
 * Input: nums = [4,5,6,7,0,1,2], target = 0
 * Output: 4
 *
 */

/**
 * ------------------------------------ Approach 1 ------------------------------------
 * Time Complexity : O(n)
 * Space Complexity : O(1)
 * Description : linear Search
 *
 */

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int idx = -1;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == target)
                return i;
        }
        return -1;
    }
};

/**
 * ------------------------------------ Approach 2 ------------------------------------
 * Time Complexity : O(logn)
 * Space Complexity : O(1)
 * Description : Binary Search by finding pivot
 *
 */
class Solution
{
public:
    int findPivort(vector<int> &nums)
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
        return low;
    }
    int binarySearch(vector<int> &nums, int low, int high, int target)
    {
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target)
                return mid;
            if (nums[mid] > target)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return -1;
    }

    int search(vector<int> &nums, int target)
    {
        int pIdx = findPivort(nums);

        int idx = binarySearch(nums, 0, pIdx - 1, target);
        if (idx != -1)
            return idx;

        idx = binarySearch(nums, pIdx, nums.size() - 1, target);
        return idx;
    }
};

/**
 * ------------------------------------ Approach 3 ------------------------------------
 * Time Complexity : O(logn)
 * Space Complexity : O(1)
 * Description : Binary Search
 */

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {

        int low = 0, high = nums.size() - 1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target)
                return mid;

            if (nums[mid] > nums[high]) // left half is sorted
            {
                // check if target lies in left half
                if (target >= nums[low] && target < nums[mid])
                    high = mid - 1;

                else // target lies in right half
                    low = mid + 1;
            }
            else // right half is sorted
            {
                // check if target lies in right half
                if (target > nums[mid] && target <= nums[high])
                    low = mid + 1;

                else // target lies in left half
                    high = mid - 1;
            }
        }
        return -1;
    }
};