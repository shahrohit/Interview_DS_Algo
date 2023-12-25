#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

// ----------------------- Introduction ------------------------------------------
// Title : Majority Element II
// LeetCode No : 229
// Difficulty : Medium
// Topics : Array, Hash Table, sorting, counting
// Link : https://leetcode.com/problems/majority-element-ii/description/

// ----------------------- Problem Statement --------------------------------------
// Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

// Input: nums = [3,2,3]
// Output: [3]

// ------------------------ Approach 1 : Hash Map ------------------------------
class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        int n = nums.size();

        unordered_map<int, int> freqMap;
        vector<int> ans;

        for (int x : nums)
        {
            if (freqMap[x] == -1) // condition for the element already pushed to array
                continue;

            freqMap[x]++;
            if (freqMap[x] > n / 3)
            {
                ans.push_back(x);
                freqMap[x] = -1; // mark the element is pushed to array
            }
        }
        return ans;
    }
};
// TC : O(n)
// SC : O(n)

// ------------------------ Approach 3 : Boyer-Moore Majority Voting  Algorithm ------------------------------
// since we are required to return the elements that appered more tha n /3
// there will only be atmost 2 elements
// so find the two possible candidates usign bouyer moore majority voting algo
// count the frequency of the two candidate if it is > n/3 then return those elements
//
class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        int n = nums.size();

        int count1 = 0, count2 = 0;
        int candidate1 = 0, candidate2 = 0;
        // First pass to find potential majority elements.
        for (int i = 0; i < n; i++)
        {
            if (count1 == 0 && nums[i] != candidate2)
            {
                count1 = 1;
                candidate1 = nums[i];
            }
            else if (count2 == 0 && nums[i] != candidate1)
            {
                count2 = 1;
                candidate2 = nums[i];
            }
            else if (nums[i] == candidate1)
            {
                count1++;
            }
            else if (nums[i] == candidate2)
            {
                count2++;
            }
            else
            {
                count1--;
                count2--;
            }
        }
        // Second pass to count occurrences of the potential majority elements.
        count1 = 0, count2 = 0;
        for (int i = 0; i < n; i++)
        {
            if (candidate1 == nums[i])
                count1++;
            else if (candidate2 == nums[i])
                count2++;
        }
        vector<int> res;
        // Check if the counts of potential majority elements are greater than n/3 and add them to the result.
        if (count1 > n / 3)
            res.push_back(candidate1);
        if (count2 > n / 3)
            res.push_back(candidate2);
        return res;
    }
};
// TC : O(n)
// SC : O(1)
