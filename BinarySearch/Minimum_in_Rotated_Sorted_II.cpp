#include <vector>
using namespace std;

/**
 * ----------------------- Introduction ------------------------------------------
 * Title : Find Minimum in Rotated Sorted Array II
 * Leetcode No :154
 * Difficulty : Hard
 * Topics : Array, Binary Search
 * Link : https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/description/
 *
 */

/**
 * ----------------------- Problem Statement ------------------------------------------
 * Given the sorted rotated array nums that may contain duplicates,
 * return the minimum element of this array.
 *
 * Input: nums = [2,2,2,0,1]
 * Output: 0
 *
 */

// ------------------------ Approach  ----------------------------

class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int low = 0, high = nums.size() - 1;
        while (low < high)
        {
            int mid = low + (high - low) / 2;
            if (nums[low] == nums[mid] && nums[mid] == nums[high])
            {
                low++;
                high--;
            }
            else if (nums[mid] > nums[high])
            {
                low = mid + 1;
            }
            else
            {
                high = mid;
            }
        }
        return nums[high];
    }
};
// TC : O(logn)
// SC : O(1)