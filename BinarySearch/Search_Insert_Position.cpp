#include <vector>
using namespace std;

/**
 * ------------------------------------ Introducion ------------------------------------
 * Title : Search Insert Position
 * LeetCode No : 35
 * Difficulty : Easy
 * Topic : Array, Binary Search
 * Link : https://leetcode.com/problems/search-insert-position/description/
 *
 */

/**
 * ------------------------------------ Problem Statement ------------------------------------
 * Given a sorted array of distinct integers and a target value, return the index if the target is found.
 * If not, return the index where it would be if it were inserted in order.
 *
 * Input: nums = [1,3,5,6], target = 5
 * Output: 2
 */

// ------------------------------------ Approach 1 ------------------------------------
class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {

        int low = 0;
        int high = nums.size() - 1;
        int ans = nums.size();

        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (nums[mid] >= target)
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return ans;
    }
};
// Time Complexity : O(log(n))
// Space Complexity : O(1)

// ------------------------------------ Approach 1 ------------------------------------
class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        return lower_bound(begin(nums), end(nums), target) - begin(nums);
    }
};

// Time Complexity : O(log(n))
// Space Complexity : O(1)