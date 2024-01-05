#include <vector>
#include <algorithm>
using namespace std;

/**
 * ------------------------------------ Introducion ------------------------------------
 * Title : Sort Array By Parity
 * LeetCode No : 905
 * Diffulty : Easy
 * Topic : Array, Two Pointers, Sorting
 * Link : https://leetcode.com/problems/sort-array-by-parity/
 *
 */

/**
 * ------------------------------------ Problem Statement ------------------------------------
 * Given an array nums of non-negative integers, return an array consisting of all the even elements of nums, followed by all the odd elements of nums.
 * You may return any answer array that satisfies this condition.
 *
 * Example 1:
 * Input: nums = [3,1,2,4]
 * Output: [2,4,3,1]
 * Explanation: The output array satisfies that:
 * nums[0] is even, 3 is odd, nums[2] is even, and 1 is odd.
 * The order of elements in the output does not matter.
 *
 * The outputs [4,2,3,1], [2,4,1,3], and [4,2,1,3] would also be accepted.
 *
 */

// ------------------------------------ Approach 1 ------------------------------------
class Solution
{
public:
    vector<int> sortArrayByParity(vector<int> &nums)
    {
        int n = nums.size();
        int evenIdx = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] % 2 == 0)
            {
                swap(nums[i], nums[evenIdx++]);
            }
        }
        return nums;
    }
};
// Time Complexity : O(n)
// Space Complexity : O(1)

// ------------------------------------ Approach 2 : Comparator Class --------------------------------
class Comparator
{
public:
    bool operator()(int &a, int &b) const
    {
        return a % 2 < b % 2;
    }
};
class Solution
{
public:
    vector<int> sortArrayByParity(vector<int> &nums)
    {
        sort(begin(nums), end(nums), Comparator());
        return nums;
    }
};
// Time Complexity : O(nlogn)
// Space Complexity : O(1)

// ------------------------------------ Approach 2 : Comparator Function --------------------------------
class Solution
{
public:
    static bool comparator(int &a, int &b)
    {
        return (a % 2) < (b % 2);
    }
    vector<int> sortArrayByParity(vector<int> &nums)
    {
        sort(begin(nums), end(nums), comparator);
        return nums;
    }
};
// Time Complexity : O(nlogn)
// Space Complexity : O(1)

// ------------------------------------ Approach 2 : Lambdas --------------------------------
class Solution
{
public:
    vector<int> sortArrayByParity(vector<int> &nums)
    {
        bool comparator = [](int &a, int &b)
        {
            return (a % 2) < (b % 2);
        };

        sort(begin(nums), end(nums), comparator);
        return nums;
    }
};
// Time Complexity : O(nlogn)
// Space Complexity : O(1)