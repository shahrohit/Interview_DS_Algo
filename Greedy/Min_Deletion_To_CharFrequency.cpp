#include <bits/stdc++.h>
using namespace std;
/**
 * ------------------------------------ Introducion ------------------------------------
 * Title : Minimum Deletions to Make Character Frequencies Unique
 * Leetcode No : 1647
 * Difficulty : Medium
 * Topic : Greedy, String, Hash Table, Sorting
 * Link : https://leetcode.com/problems/minimum-deletions-to-make-character-frequencies-unique/
 *
 */

/**
 * ------------------------------------ Problem Statement ------------------------------------
 * A string s is called good if there are no two different characters in s that have the same frequency.
 *
 * Given a string s, return the minimum number of characters you need to delete to make s good.
 * The frequency of a character in a string is the number of times it appears in the string.
 * For example, in the string "aab", the frequency of 'a' is 2, while the frequency of 'b' is 1.
 *
 * Input: s = "aab"
 * Output: 0
 *
 * Input: s = "aaabbbcc"
 * Output: 2
 */

// ------------------------------------ Approach 1 : Hash Table ----------------------------------
class Solution
{
public:
    int minDeletions(string s)
    {
        vector<int> freq(26, 0);
        for (auto &ch : s)
        {
            freq[ch - 'a']++;
        }
        int result = 0;
        unordered_set<int> set;
        for (int i = 0; i < 26; i++)
        {

            while (freq[i] > 0 && set.count(freq[i]))
            {
                freq[i]--;
                result++;
            }
            set.insert(freq[i]);
        }
        return result;
    }
};
// Time Complexity : O(n)
// Space Complexity : O(n)

// ------------------------------------ Approach 2 : Sorting ------------------------------------
class Solution
{
public:
    int minDeletions(string s)
    {

        vector<int> freq(26, 0);
        for (auto &ch : s)
        {
            freq[ch - 'a']++;
        }

        sort(freq.begin(), freq.end(), greater<int>());

        int deleteCount = 0;
        for (int i = 1; i < 26; i++)
        {

            if (freq[i] >= freq[i - 1])
            {
                int prev = freq[i];
                freq[i] = max(0, freq[i - 1] - 1);
                deleteCount += (prev - freq[i]);
            }
        }
        return deleteCount;
    }
};

// Time Complexity : O(26log(26) + n)
// Space Complexity : O(1)