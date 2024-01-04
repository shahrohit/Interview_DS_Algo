#include <vector>
#include <algorithm>

using namespace std;

/**
 * ------------------------------------ Introducion ------------------------------------
 * Title : Reduction Operations to Make the Array Elements Equal
 * LeetCode No : 1887
 * Diffulty : Medium
 * Topic : Array, Sorting
 * Link : https://leetcode.com/problems/reduction-operations-to-make-the-array-elements-equal/description/
 *
 */

/**
 * ------------------------------------ Problem Statement ------------------------------------
 * Given an integer array nums, your goal is to make all elements in nums equal.
 * To complete one operation, follow these steps:
 * 1. Find the largest value in nums. Let its index be i (0-indexed) and its value be largest.
 * If there are multiple elements with the largest value, pick the smallest i.
 * 2. Find the next largest value in nums strictly smaller than largest. Let its value be nextLargest.
 * 3. Reduce nums[i] to nextLargest.
 * Return the number of operations to make all elements in nums equal.
 *
 * Input: nums = [5,1,3]
 * Output: 3
 * Explanation: It takes 3 operations to make all elements in nums equal:
 *
 */

// ------------------------------------ Approach 1 ------------------------------------
class Solution
{
public:
    int reductionOperations(vector<int> &nums)
    {
        sort(begin(nums), end(nums));

        int n = nums.size();
        int ops = 0;
        for (int i = n - 1; i > 0; i--)
        {
            if (nums[i] == nums[i - 1])
                continue;
            ops += (n - i);
        }

        return ops;
    }
};

// Time Complexity : O(nlog(n))
// Space Complexity : O(1)