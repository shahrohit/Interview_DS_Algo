#include <vector>
#include <unordered_map>
using namespace std;

// ----------------------- Introduction ------------------------------------------
// Title : Subarray Sums Divisible by K
// LeetCode No : 974
// Difficulty : Medium
// Topics : Array, Hash Table, Math
// Link : https://leetcode.com/problems/subarray-sums-divisible-by-k/description/

// ----------------------- Problem Statement --------------------------------------
// Given an integer array nums and an integer k, return the number of non-empty subarrays
// that have a sum divisible by k.

// Input: nums = [4,5,0,-2,-3,1], k = 5
// Output: 7
// Explanation: There are 7 subarrays with a sum divisible by k = 5:
// [4, 5, 0, -2, -3, 1], [5], [5, 0], [5, 0, -2, -3], [0], [0, -2, -3], [-2, -3]

// ------------------------ Approach 1 : Brute Force ------------------------------
class Solution
{
public:
    int subarraysDivByK(vector<int> &nums, int k)
    {

        int n = nums.size();
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            int sum = 0;
            for (int j = i; j < n; j++)
            {
                sum += nums[j];
                if (sum % k == 0)
                    count++;
            }
        }
        return count;
    }
};
// T.C : O(n*n)
// S.C : O(1)

// ------------------------ Approach 1 : Basic Maths ------------------------------
// num[] = {a,b,c,d,e,f,g}
// let s1 = a + b + c + d + e
// let s2 = a + b
// if s1 % k = x and s2 % k = x
// then (c + d + e) % k = 0 divisible by k
class Solution
{
public:
    int subarraysDivByK(vector<int> &nums, int k)
    {

        int n = nums.size();
        unordered_map<int, int> remFreq;
        int sum = 0;
        int result = 0;
        remFreq[0] = 1;

        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
            int rem = sum % k;
            if (rem < 0) // for the cases like negative remainder so convert to positive
                rem += k;

            if (remFreq.find(rem) != remFreq.end())
            {
                result += remFreq[rem];
            }
            remFreq[rem]++;
        }
        return result;
    }
};
// T.C : O(n)
// S.C : O(n)