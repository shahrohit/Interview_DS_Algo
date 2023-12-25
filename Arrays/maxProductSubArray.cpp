#include <vector>
#include <limits.h>
using namespace std;

// ----------------------- Introduction ------------------------------------------
// Title : Maximum Product Subarray
// LeetCode No : 152
// Difficulty : Medium
// Topics : Array, Divide Conqure, DP
// Link : https://leetcode.com/problems/maximum-product-subarray/description/

// ----------------------- Problem Statement --------------------------------------
// Input: nums = [-2,-3,-2,4]
// Output: 24
// Explanation: [-3,-2,4] has the largest product 24.

// ----------------------- Approach 1 : Brute Force ---------------------------------
class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {

        int n = nums.size();
        int maxProd = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            int currProd = 1;
            for (int j = i; j < n; j++)
            {
                currProd = currProd * nums[j];
                maxProd = max(maxProd, currProd);
            }
        }
        return maxProd;
    }
};
// TC : O(n * n)
// SC : O(1)

// ------------------------ Approach 2 : kadanes Algo ------------------------------
class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {

        int n = nums.size();
        int maxProd = INT_MIN;
        int currProd = 1;
        // max Product from left to right
        for (int i = 0; i < n; i++)
        {
            currProd *= nums[i];
            maxProd = max(maxProd, currProd);
            if (currProd == 0)
                currProd = 1;
        }
        currProd = 1;
        // max Product from right to left
        for (int i = n - 1; i >= 0; i--)
        {
            currProd *= nums[i];
            maxProd = max(maxProd, currProd);
            if (currProd == 0)
                currProd = 1;
        }

        return maxProd;
    }
};
// TC : O(n)
// SC : O(1)