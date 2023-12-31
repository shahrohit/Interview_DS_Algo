#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

// ----------------------- Introduction ------------------------------------------
// Title : Largest Substring Between Two Equal Characters
// LeetCode No : 1624
// Difficulty : Medium
// Topics : Hash Table, String
// Link : https://leetcode.com/problems/largest-substring-between-two-equal-characters/description/

// ----------------------- Problem Statement --------------------------------------

// Given a string s, return the length of the longest substring between two equal characters,
// excluding the two characters. If there is no such substring return -1.

// A substring is a contiguous sequence of characters within a string.

// Input: s = "abca"
// Output: 2
// Explanation: The optimal substring here is "bc".

// ----------------------- Approach 1 :  ---------------------------------
class Solution
{
public:
    int maxLengthBetweenEqualCharacters(string s)
    {
        unordered_map<char, int> map;
        int n = s.size();
        // store the right most index of everry character
        for (int i = 0; i < n; i++)
        {
            map[s[i]] = i;
        }
        int maxLen = -1;
        for (int i = 0; i < n; i++)
        {

            int rightMostIdx = map[s[i]];
            int currLen = (rightMostIdx - i - 1);
            maxLen = max(maxLen, currLen);
        }
        return maxLen;
    }
};
// T.C : O(n)
// S.C : O(n)

// ------------------------ Approach 2 :  ------------------------------
class Solution
{
public:
    int maxLengthBetweenEqualCharacters(string s)
    {
        // store the right most index of everry character
        vector<int> rightMostIdx(26, -1);
        int n = s.size();
        for (int i = 0; i < n; i++)
        {
            rightMostIdx[s[i] - 'a'] = i;
        }
        int maxLen = -1;
        for (int i = 0; i < n; i++)
        {

            int j = rightMostIdx[s[i] - 'a'];
            int currLen = (j - i - 1);
            maxLen = max(maxLen, currLen);
        }
        return maxLen;
    }
};
// T.C : O(n)
// S.C : O(1)