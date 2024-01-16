#include <bits/stdc++.h>
using namespace std;
/**
 * ------------------------------------ Introducion ------------------------------------
 * Title : Break a Plandrome
 * Leetcode No : 1328
 * Difficulty : Medium
 * Topic : Greedy, String
 * Link : https://leetcode.com/problems/break-a-palindrome/
 *
 */

/**
 * ------------------------------------ Problem Statement ------------------------------------
 * Given a palindromic string of lowercase English letters palindrome,
 * replace exactly one character with any lowercase English letter so that
 * the resulting string is not a palindrome and that it is the lexicographically smallest one possible.
 * Return the resulting string. If there is no way to replace a character to make it not a palindrome,
 * return an empty string.
 *
 * Input: palindrome = "abccba"
 * Output: "aaccba"
 *
 * Input: palindrome = "a"
 * Output: ""
 */

// ------------------------------------ Approach 1 ------------------------------------

class Solution
{
public:
    string breakPalindrome(string palindrome)
    {
        int n = palindrome.size();
        // if size is 1, then it is already a palindrome
        if (n == 1)
        {
            return "";
        }
        // find the first character which is not 'a' and replace it with 'a'
        for (int i = 0; i < n / 2; i++)
        {
            if (palindrome[i] != 'a')
            {
                palindrome[i] = 'a';
                return palindrome;
            }
        }
        // if all characters are 'a', then replace the last character with 'b'
        palindrome[n - 1] = 'b';
        return palindrome;
    }
};

// Time Complexity : O(n)
// Space Complexity : O(1)