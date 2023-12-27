#include <vector>
#include <unordered_map>
using namespace std;

// ----------------------- Introduction ------------------------------------------
// Title : Continuous SubArray Sum
// LeetCode No : 523
// Difficulty : Medium
// Topics : Array, Hash Table, Math
// Link : https://leetcode.com/problems/continuous-subarray-sum/description/

// ----------------------- Problem Statement --------------------------------------
// Given an integer array nums and an integer k, return true if nums has a good subarray or false otherwise.
// A good subarray is a subarray where:
// a. its length is at least two, and
// b. the sum of the elements of the subarray is a multiple of k.

// Input: nums = [23,2,4,6,7], k = 6
// Output: true
// Explanation: [2, 4] is a continuous subarray of size 2 whose elements sum up to 6

// ------------------------ Approach 1 : Brute Force ------------------------------
class Solution
{
public:
    bool checkSubarraySum(vector<int> &nums, int k)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            int sum = 0;
            for (int j = i; j < nums.size(); j++)
            {
                sum += nums[i];
                if ((j - i) >= 1 && (sum % k == 0))
                    return true;
            }
        }
        return false;
    }
};
// T.C : O(n*n)
// S.C : O(1)

// ------------------------ Approach 1 : Basic Maths ------------------------------
// nums[] = {23,2,4,6,7}, k = 6
// 23 % 6 = 5
// (23 + 2) % 6 = 1
// (23 + 2 + 4) % 6 = 5 (remainder already exist)
// which means,  (2 + 4 = 6) is divisible by 6
class Solution
{
public:
    bool checkSubarraySum(vector<int> &nums, int k)
    {
        // map of remainder, index
        unordered_map<int, int> map;
        int sum = 0;
        map[0] = -1; // for the case like [1,2,3]
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            int rem = sum % k;
            if (map.find(rem) == map.end())
                map[rem] = i;

            else if (i - map[rem] >= 2)
                return true;
        }
        return false;
    }
};
// T.C : O(n)
// S.C : O(n)