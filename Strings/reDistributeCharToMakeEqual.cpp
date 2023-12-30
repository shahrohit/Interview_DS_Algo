#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

// ----------------------- Introduction ------------------------------------------
// Title : Redistribute Characters to Make All Strings Equal
// LeetCode No : 1897
// Difficulty : Easy
// Topics : String, HashMap, Counting
// Link : https://leetcode.com/problems/redistribute-characters-to-make-all-strings-equal/

// ----------------------- Problem Statement --------------------------------------
// You are given an array of strings words (0-indexed).
// In one operation, pick two distinct indices i and j,
// where words[i] is a non-empty string, and move any character from words[i] to any position in words[j].
// Return true if you can make every string in words equal using any number of operations, and false otherwise.

// Input: words = ["abc","aabc","bc"]
// Output: true
// Explanation: Move the first 'a' in words[1] to the front of words[2],
// to make words[1] = "abc" and words[2] = "abc".
// All the strings are now equal to "abc", so return true.

// ----------------------- Approach 1 : Hash Map ---------------------------------
class Solution
{
public:
    bool makeEqual(vector<string> &words)
    {
        unordered_map<char, int> map;

        for (auto &word : words)
        {
            for (auto &ch : word)
                map[ch]++;
        }
        int n = words.size();
        for (auto &[ch, freq] : map)
        {
            if (freq % n != 0)
                return false;
        }
        return true;
    }
};
// T.C : O(n)
// S.C : O(n)

// ------------------------ Approach 2 :  ------------------------------
class Solution
{
public:
    bool makeEqual(vector<string> &words)
    {
        vector<int> freq(26, 0);

        for (auto &word : words)
        {
            for (auto &ch : word)
                freq[ch - 'a']++;
        }
        int n = words.size();
        for (auto &count : freq)
        {
            if (count % n != 0)
                return false;
        }
        return true;
    }
};
// T.C : O(n)
// S.C : O(1)

// ------------------------ Approach 3 : using stl  ------------------------------
class Solution
{
public:
    bool makeEqual(vector<string> &words)
    {
        vector<int> freq(26, 0);

        for (auto &word : words)
        {
            for (auto &ch : word)
                freq[ch - 'a']++;
        }
        int n = words.size();

        auto lambda = [&](int &count)
        { return (count % n == 0); };

        return all_of(begin(freq), end(freq), lambda);
    }
};