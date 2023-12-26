#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

// ----------------------- Introduction ------------------------------------------
// Title : Group Anagrams
// LeetCode No : 49
// Difficulty : Medium
// Topics : Array, Hash Table, String, Sorting
// Link : https://leetcode.com/problems/group-anagrams/description/

// ----------------------- Problem Statement --------------------------------------

// Given an array of strings strs, group the anagrams together. You can return the answer in any order.
// An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase,
// typically using all the original letters exactly once.

// Input: strs = ["eat","tea","tan","ate","nat","bat"]
// Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
// strs[i] consists of lowercase English letters.

// ----------------------- Approach 1 : Brute Force ---------------------------------

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        // map of sorted string to the original string
        unordered_map<string, vector<string>> map;
        vector<vector<string>> ans;

        int n = strs.size();
        for (int i = 0; i < n; i++)
        {
            string temp = strs[i];
            sort(temp.begin(), temp.end());
            map[temp].push_back(strs[i]);
        }

        for (auto str : map)
        {
            ans.push_back(str.second);
        }
        return ans;
    }
};
// T.C : O(n * k * log(k)) where k is length of longest word
// S.C : O(n)

// ------------------------ Approach 2 : Optimal Approach ------------------------------
class Solution
{
public:
    // get the sorted word
    string findSortedWord(string &word)
    {
        vector<int> freq(26, 0);
        for (char &letter : word)
        {
            freq[letter - 'a']++;
        }

        string sortedWord = "";
        for (int i = 0; i < 26; i++)
        {
            if (freq[i] != 0)
            {
                sortedWord += string(freq[i], 'a' + i);
            }
        }
        return sortedWord;
    }

    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> map;
        for (auto &word : strs)
        {
            string key = findSortedWord(word);
            map[key].push_back(word);
        }
        vector<vector<string>> anagram;
        for (auto &[key, words] : map)
        {
            anagram.push_back(words);
        }
        return anagram;
    }
};

// T.C : O(n * k) , where k is length of longest word
// S.C : O(n)