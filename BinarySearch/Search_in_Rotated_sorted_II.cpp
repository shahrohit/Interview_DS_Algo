#include <vector>
#include <algorithm>
using namespace std;

/**
 * ------------------------------------ Introducion ------------------------------------
 * Title : Search in Rotated Sorted Array II
 * LeetCode No : 81
 * Difficulty : Medium
 * Topic : Binary Search
 * Link : https://leetcode.com/problems/search-in-rotated-sorted-array-ii/
 *
 */

/**
 * ------------------------------------ Problem Statement ------------------------------------
 * Find the index of the target element in the given sorted and rotated array.
 * Elemet may be repeated.
 * If not found, return -1.
 *
 * Input: nums = [2,5,6,0,0,1,2], target = 0
 * Output: true
 *
 * Input: nums = [2,5,6,0,0,1,2], target = 3
 * Output: false
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
    bool search(vector<int> &nums, int target)
    {
        int idx = -1;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == target)
                return true;
        }
        return false;
    }
};

/**
 * ------------------------------------ Approach 2 ------------------------------------
 * Time Complexity : O(logn)
 * Space Complexity : O(1)
 * Description : Binary Search
 *
 */

class Solution
{
public:
    bool search(vector<int> &nums, int target)
    {
        int low = 0, high = nums.size() - 1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target)
                return true;

            if ((nums[mid] == nums[low]) && (nums[mid] == nums[high]))
            {
                low++;
                high--;
            }
            else if (nums[mid] > nums[high])
            {
                if (target >= nums[low] && target < nums[mid])
                    high = mid - 1;
                else
                    low = mid + 1;
            }
            else
            {
                if (target > nums[mid] && target <= nums[high])
                    low = mid + 1;
                else
                    high = mid - 1;
            }
        }
        return false;
    }
};