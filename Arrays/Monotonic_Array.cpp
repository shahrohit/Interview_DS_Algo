#include <vector>
using namespace std;

/**
 * ------------------------------------ Introducion ------------------------------------
 * Title : Monotonic Array
 * LeetCode No : 896
 * Diffulty : Easy
 * Topic : Array
 * Link : https://leetcode.com/problems/monotonic-array/description/
 *
 */

/**
 * ------------------------------------ Problem Statement ------------------------------------
 * An array is monotonic if it is either monotone increasing or monotone decreasing.
 * An array A is monotone increasing if for all i <= j, A[i] <= A[j].
 * An array A is monotone decreasing if for all i <= j, A[i] >= A[j].
 * Return true if and only if the given array A is monotonic.
 *
 * Example 1:
 * Input: [1,2,2,3]
 * Output: true
 *
 * Example 2:
 * Input: [6,5,4,4]
 * Output: true
 *
 * Example 3:
 * Input: [1,3,2]
 * Output: false
 *
 */

// ------------------------------------ Approach 1 ------------------------------------
class Solution
{
public:
    bool isMonotonic(vector<int> &nums)
    {
        bool inc = true, dec = true;

        int n = nums.size();

        for (int i = 0; i < n - 1; i++)
        {

            if (nums[i] > nums[i + 1])
            {
                inc = false;
            }
            else if (nums[i] < nums[i + 1])
            {
                dec = false;
            }
            if (!inc && !dec)
                return false;
        }
        return inc || dec;
    }
};