#include <string>
using namespace std;

// ----------------------- Introduction ------------------------------------------
// Title : Merge Strings Alternately
// LeetCode No : 1768
// Difficulty : Easy
// Topics : String, Two pointers
// Link : https://leetcode.com/problems/merge-strings-alternately/description/

// ----------------------- Problem Statement --------------------------------------
// You are given two strings word1 and word2. Merge the strings by adding letters in alternating order, starting with word1.
// If a string is longer than the other, append the additional letters onto the end of the merged string.
// Return the merged string.
// Input: word1 = "abc", word2 = "pqr"
// Output: "apbqcr"
// Explanation: The merged string will be merged as so:
// word1:  a   b   c
// word2:    p   q   r
// merged: a p b q c r

// ----------------------- Approach 1 ---------------------------------
// After merging we notice,
// At even idx, charater is from word1,
// At odd idx, character is from word1,
// for addtional length, just add the remaning the character
class Solution
{
public:
    string mergeAlternately(string word1, string word2)
    {
        int n1 = word1.size();
        int n2 = word2.size();
        int i = 0, j = 0;

        string ans;
        while (i < n1 && j < n2)
        {
            // even length => append a character from word 1
            if (ans.size() % 2 == 0)
                ans += word1[i++];
            // odd length => append a character from word2;
            else
                ans += word2[j++];
        }

        while (i < n1)
            ans += word1[i++]; // extra character in word1
        while (j < n2)
            ans += word2[j++]; // extra character in word2

        return ans;
    }
};
// T.C : O(max(n1,n2))
// S.C : O(1)
