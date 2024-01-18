#include <bits/stdc++.h>
using namespace std;
/**
 * ------------------------------------ Introducion ------------------------------------
 * Title : Optimal Partition of String
 * Leetcode No : 2405
 * Difficulty : Medium
 * Topic : Greedy, String, Hash Table
 * Link : https://leetcode.com/problems/optimal-partition-of-a-string/
 *
 */

/**
 * ------------------------------------ Problem Statement ------------------------------------
 * Given a string s, partition s such that every substring of the partition is a palindrome.
 * Return the minimum cuts needed for a palindrome partitioning of s.
 *
 * Input: s = "abacaba"
 * Output: 4
 * Explanation:
 * Two possible partitions are ("a","ba","cab","a") and ("ab","a","ca","ba").
 * It can be shown that 4 is the minimum number of substrings needed.
 */

// ------------------------------------ Approach 1 ------------------------------------
class Solution
{
public:
    int partitionString(string s)
    {
        unordered_set<int> set;
        int count = 1;
        // if there is a character that is already present in the set, then we need to make a cut
        for (char &ch : s)
        {
            if (set.count(ch))
            {
                count++;
                set.clear();
            }
            set.insert(ch);
        }
        return count;
    }
};
// Time Complexity : O(n)
// Space Complexity : O(n)

// ------------------------------------ Approach 2 ------------------------------------
class Solution
{
public:
    int partitionString(string s)
    {
        vector<int> visited(26, 0);
        int count = 1;
        for (char &ch : s)
        {
            int chIdx = ch - 'a';
            if (visited[chIdx])
            {
                count++;
                visited.assign(26, 0);
            }
            visited[chIdx] = 1;
        }
        return count;
    }
};

// Time Complexity : O(n)
// Space Complexity : O(1)