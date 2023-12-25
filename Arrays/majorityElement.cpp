#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

// ----------------------- Introduction ------------------------------------------
// Title : Majority Element
// LeetCode No : 169
// Difficulty : Easy
// Topics : Array, Hash Table, sorting, counting
// Link : https://leetcode.com/problems/majority-element/description/

// ----------------------- Problem Statement --------------------------------------
// Given an array nums of size n, return the majority element.
// The majority element is the element that appears more than ⌊n / 2⌋ times.
// You may assume that the majority element always exists in the array.
// Input: nums = [2,2,1,1,1,2,2]
// Output: 2

// ----------------------- Approach 1 : Sorting ---------------------------------
class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        return nums[nums.size() / 2];
    }
};
// TC : O(n * log(n))
// SC : O(1)

// ------------------------ Approach 2 : Hash Map ------------------------------
class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        unordered_map<int, int> freqMap;
        int n = nums.size();
        int majority;
        for (int &num : nums)
        {
            freqMap[num]++;
            if (freqMap[num] > n / 2)
            {
                majority = num;
                break;
            }
        }
        return majority;
    }
};
// TC : O(n)
// SC : O(n)

// ------------------------ Approach 3 : Moore Voting Algorithm ------------------------------
// The intuition behind the Moore's Voting Algorithm is based on the fact that
// if there is a majority element in an array,
// it will always remain in the lead, even after encountering other elements.

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {

        int candidate = 0;
        int count = 0;

        for (int x : nums)
        {
            if (count == 0)
                candidate = x;

            if (candidate == x)
                count++;
            else
                count--;
        }
        return candidate;
    }
};
// TC : O(n)
// SC : O(1)
