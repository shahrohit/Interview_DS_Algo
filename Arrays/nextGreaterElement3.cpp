#include <string>
#include <algorithm>
using namespace std;

// ----------------------- Introduction ------------------------------------------
// Title : Next Greater Element III
// LeetCode No : 556
// Difficulty : Medium
// Topics : Math, string
// Link : https://leetcode.com/problems/majority-element-ii/description/

// ----------------------- Problem Statement --------------------------------------
// Given a positive integer n, find the smallest integer which has exactly the same digits existing in the integer n and is greater in value than n.
// If no such positive integer exists, return -1.
// Input: n = 2458631
// Output: 2461358

// ------------------------ Approach 1 ------------------------------
class Solution
{
public:
    int nextGreaterElement(int n)
    {
        // convert number to string
        string digits = to_string(n);
        // find a digit that is less than than the next digit
        int j = digits.size() - 2;
        while (j >= 0 && digits[j] >= digits[j + 1])
        {
            j--;
        }
        // number it self is maximum
        if (j == -1)
            return -1;

        // find the next greater element
        int k = digits.size() - 1;
        while (digits[j] >= digits[k])
            k--;

        // swap
        swap(digits[j], digits[k]);
        // reverse the rest end digites
        reverse(digits.begin() + j + 1, digits.end());

        long ans = stol(digits);
        if (ans > INT_MAX)
            return -1;
        return ans;
    }
};

// TC : O(n)
// SC : O(n)