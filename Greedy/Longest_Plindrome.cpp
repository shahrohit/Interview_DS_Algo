#include <bits/stdc++.h>
using namespace std;
/**
 * ------------------------------------ Introducion ------------------------------------
 * Title : Longest Palindrome by Concatenating Two Letter Words
 * Leetcode No : 2131
 * Difficulty : Medium
 * Topic :Array, Hash Table, Greedy
 * Link : https://leetcode.com/problems/longest-palindrome-by-concatenating-two-letter-words/
 *
 */

/**
 * ------------------------------------ Problem Statement ------------------------------------
 * You are given an array of strings words and a string allowed consisting of distinct characters.
 * A string is consistent if all characters in the string appear in the string allowed.
 * Return the length of the longest consistent string in the array words.
 *
 * Example 1:
 * Input: words = ["ab","ba","abc","cba","bca","bac"]
 * Output: 4
 *
 */

// ------------------------------------ Approach 1 ------------------------------------
class Solution
{
public:
    int longestPalindrome(vector<string> &words)
    {
        unordered_map<string, int> map;
        for (string &word : words)
        {
            map[word]++;
        }
        int length = 0;

        bool centralUsed = false;

        for (auto &word : words)
        {
            // if two characters of word is same
            if (word[0] == word[1])
            {
                // if count of word is greater than 2
                if (map[word] >= 2)
                {
                    length += 4;
                    map[word] -= 2;
                }
                // if count of word is 1 and central character is not used
                else if (map[word] == 1 && centralUsed == false)
                {
                    length += 2;
                    map[word] -= 1;
                    centralUsed = true;
                }
            }
            else // if two characters of word is not same
            {
                string rev = word;
                swap(rev[0], rev[1]);

                if (map[word] >= 1 && map[rev] >= 1)
                {
                    length += 4;
                    map[word]--;
                    map[rev]--;
                }
            }
        }
        return length;
    }
};
// Time Complexity : O(n)
// Space Complexity : O(n)