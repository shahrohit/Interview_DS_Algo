#include <vector>
#include <math.h>
using namespace std;

// ----------------------- Introduction ------------------------------------------
// Title : Set Mismatch
// LeetCode No :  645
// Difficulty : Easy
// Topics : Array
// Link : https://leetcode.com/problems/set-mismatch/description/

// ----------------------- Problem Statement --------------------------------------

// You have a set of integers s, which originally contains all the numbers from 1 to n.
// Unfortunately, due to some error, one of the numbers in s got duplicated to another number in the set,
// which results in repetition of one number and loss of another number.

// You are given an integer array nums representing the data status of this set after the error.

// Find the number that occurs twice and the number that is missing and return them in the form of an array.

// Input: nums = [1,2,2,4]
// Output: [2,3]

// ------------------------------ Approach 1 ----------------------------------------
class Solution
{
public:
    vector<int> findErrorNums(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> result(2);
        // finding the reapted number
        for (int i = 0; i < n; i++)
        {
            int idx = abs(nums[i]) - 1;
            if (nums[idx] < 0)
                result[0] = idx + 1;
            else
                nums[idx] = -nums[idx];
        }
        // finding missing number
        for (int i = 0; i < n; i++)
        {
            if (nums[i] < 0)
            {
                nums[i] = -nums[i];
            }
            else
            {
                result[1] = i + 1;
            }
        }
        return result;
    }
};
// T.C : O(n))
// S.C : O(1)