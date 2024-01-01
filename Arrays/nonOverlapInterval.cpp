#include <vector>
#include <algorithm>
using namespace std;

// ----------------------- Introduction ------------------------------------------
// Title : Non-overlapping Intervals
// LeetCode No : 435
// Difficulty : Medium
// Topics : Array, Greedy , Sorting
// Link : https://leetcode.com/problems/non-overlapping-intervals/description/

// ----------------------- Problem Statement --------------------------------------
// Given an array of intervals intervals where intervals[i] = [starti, endi],
// return the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.

// Input: intervals = [[1,2],[2,3],[3,4],[1,3]]
// Output: 1
// Explanation: [1,3] can be removed and the rest of the intervals are non-overlapping.

// ---------------------------- Approach 1  ---------------------------------------
class Solution
{
public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        int n = intervals.size();

        sort(begin(intervals), end(intervals));

        vector<int> prevInterval = intervals[0];
        int count = 0;

        for (int i = 1; i < n; i++)
        {

            if (intervals[i][0] < prevInterval[1])
            {
                count++;
                if (prevInterval[1] > intervals[i][1])
                    prevInterval = intervals[i];
            }
            else
            {
                prevInterval = intervals[i];
            }
        }
        return count;
    }
};
// T.C : O(n)
// S.C : (1)