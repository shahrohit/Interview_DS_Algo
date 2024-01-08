#include <vector>
#include <algorithm>
using namespace std;

// ----------------------- Introduction ------------------------------------------
// Title : Longest Subsequence With Limited Sum
// LeetCode No : 2389
// Difficulty : Easy
// Topics : Array, Binary Search, Sorting, Prefix Sum
// Link : https://leetcode.com/problems/longest-subsequence-with-limited-sum/description/

// ----------------------- Problem Statement --------------------------------------
// You are given an integer array nums of length n, and an integer array queries of length m.
// Return an array answer of length m where answer[i] is the maximum size of a subsequence
// that you can take from nums such that the sum of its elements is less than or equal to queries[i].

// Input: nums = [4,5,2,1], queries = [3,10,21]
// Output: [2,3,4]

// ----------------------- Approach 1 : Brute Force ---------------------------------

class Solution
{
public:
    vector<int> answerQueries(vector<int> &nums, vector<int> &queries)
    {

        int m = queries.size();
        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<int> answer(m);
        for (int i = 0; i < m; i++)
        {
            int target = queries[i];
            int size = 0;
            for (int j = 0; j < n; j++)
            {
                if (nums[j] > target)
                    continue;
                target -= nums[j];
                size++;

                if (target == 0)
                    break;
            }
            answer[i] = size;
        }
        return answer;
    }
};
// T.C : (nlog(n) + m * n)
// S.C : (1)

// ---------------------------------- Approach 2 : Binary Search --------------------------------

class Solution
{
public:
    vector<int> answerQueries(vector<int> &nums, vector<int> &queries)
    {

        int m = queries.size();
        int n = nums.size();
        sort(nums.begin(), nums.end());

        for (int i = 1; i < n; i++)
            nums[i] += nums[i - 1];

        vector<int> answer(m);
        for (int i = 0; i < m; i++)
        {
            // binary Search
            // if you use lower bound you have add 1 to get the the size
            int size = upper_bound(begin(nums), end(nums), queries[i]) - nums.begin();
            answer[i] = size;
        }
        return answer;
    }
};
// T.C : ((m + n)log(n))
// S.C : (1)