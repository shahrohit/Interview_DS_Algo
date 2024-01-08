#include <vector>
using namespace std;

/**
 * ------------------------------------ Introducion ------------------------------------
 * Title : Single Element in a Sorted Array
 * LeetCode No : 540
 * Difficulty : Medium
 * Topic : Binary Search
 * Link : https://leetcode.com/problems/single-element-in-a-sorted-array/
 *
 */

/**
 * ------------------------------------ Problem Statement ------------------------------------
 * You are given a sorted array consisting of only integers where every element appears exactly twice,
 * except for one element which appears exactly once. Find this single element that appears only once.
 *
 * Example 1:
 * Input: [1,1,2,3,3,4,4,8,8]
 * Output: 2
 */

/**
 * ------------------------------------ Approach 1 ------------------------------------
 * Time Complexity : O(n)
 * Space Complexity : O(1)
 * Description : XOR
 */
class Solution
{
public:
    int singleNonDuplicate(vector<int> &nums)
    {
        int ans = nums[0];

        for (int i = 1; i < nums.size(); i++)
        {
            ans = (ans ^ nums[i]);
        }

        return ans;
    }
};

/**
 * ------------------------------------ Approach 2 ------------------------------------
 * Time Complexity : O(logn)
 * Space Complexity : O(1)
 * Description : Apply Binary Search
 */

class Solution
{
public:
    int singleNonDuplicate(vector<int> &nums)
    {

        int low = 0, high = nums.size() - 1;

        while (low < high)
        {
            int mid = low + (high - low) / 2;

            if (mid % 2 == 0)
            {
                if (nums[mid] == nums[mid + 1])
                    low = mid + 2;
                else
                    high = mid;
            }
            else
            {
                if (nums[mid] == nums[mid - 1])
                    low = mid + 1;
                else
                    high = mid;
            }
        }

        return nums[low];
    }
};