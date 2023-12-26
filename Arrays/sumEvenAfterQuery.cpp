#include <vector>
using namespace std;

// ----------------------- Introduction ------------------------------------------
// Title : Sum of Even Numbers After Queries
// LeetCode No : 985
// Difficulty : Easy
// Topics : Array
// Link : https://leetcode.com/problems/sum-of-even-numbers-after-queries/description/

// ----------------------- Problem Statement --------------------------------------
// You are given an integer array nums and an array queries where queries[i] = [vali, indexi].
// For each query i, first, apply nums[indexi] = nums[indexi] + vali, then print the sum of the even values of nums.
// Return an integer array answer where answer[i] is the answer to the ith query.

// Input: nums = [1,2,3,4], queries = [[1,0],[-3,1],[-4,0],[2,3]]
// Output: [8,6,2,4]
// Explanation: At the beginning, the array is [1,2,3,4].
// [1,0] : After adding 1 to nums[0], the array is [2,2,3,4], and the sum of even values is 2 + 2 + 4 = 8.
// [-3,1]: After adding -3 to nums[1], the array is [2,-1,3,4], and the sum of even values is 2 + 4 = 6.
// [-4,0] : After adding -4 to nums[0], the array is [-2,-1,3,4], and the sum of even values is -2 + 4 = 2.
// [2,3] : After adding 2 to nums[3], the array is [-2,-1,3,6], and the sum of even values is -2 + 6 = 4.

// ----------------------- Approach 1 ---------------------------------

class Solution
{
public:
    vector<int> sumEvenAfterQueries(vector<int> &nums, vector<vector<int>> &queries)
    {
        int evenSum = 0;
        for (int &num : nums)
        {
            if (num % 2 == 0)
                evenSum += num;
        }
        vector<int> result;
        for (auto query : queries)
        {
            int val = query[0];
            int index = query[1];

            if (nums[index] % 2 == 0)
                evenSum -= nums[index];

            nums[index] += val;

            if (nums[index] % 2 == 0)
                evenSum += nums[index];
            result.push_back(evenSum);
        }
        return result;
    }
};
// T.C : O(n + m) where, n => no of elements in nums, m => total no. of query in queries
// S.C : O(1)