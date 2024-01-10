#include <bits/stdc++.h>
using namespace std;
/**
 * ------------------------------------ Introducion ------------------------------------
 * Title : Single Number
 * Leetcode No : 136
 * Difficulty : Easy
 * Topic : Array, Bit Manipulation
 * Link : https://leetcode.com/problems/single-number/description/
 *
 */

/**
 * ------------------------------------ Problem Statement ------------------------------------
 * Given a non-empty array of integers nums,
 * every element appears twice except for one. Find that single one.
 *
 * Input: nums = [4,1,2,1,2]
 * Output: 4
 */

/**
 * ------------------------------------ Approach 1 ------------------------------------
 * Time Complexity : O(n)
 * Space Complexity : O(1)
 * Solved By : Math
 */
class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {

        int single = 0;
        for (int &x : nums)
        {
            single = (single ^ x);
        }
        return single;
    }
};