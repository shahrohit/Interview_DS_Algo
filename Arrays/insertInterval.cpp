#include <vector>
using namespace std;

// ----------------------- Introduction ------------------------------------------
// Title : Insert Interval
// LeetCode No : 57
// Difficulty : Medium
// Topics : Array
// Link : https://leetcode.com/problems/insert-interval/

// ----------------------- Problem Statement --------------------------------------
// You are given an array of non-overlapping intervals intervals where intervals[i] = [starti, endi]
// represent the start and the end of the ith interval and intervals is sorted in ascending order by starti.
// You are also given an interval newInterval = [start, end] that represents the start and end of another interval.
// Insert newInterval into intervals such that intervals is still sorted in ascending order
// by starti and intervals still does not have any overlapping intervals (merge overlapping intervals if necessary).
// Return intervals after the insertion.

// Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
// Output: [[1,2],[3,10],[12,16]]
// Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].

// ------------------------ Approach 1: ------------------------------
class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {

        int n = intervals.size();
        vector<vector<int>> ans;
        int i = 0;
        while (i < n)
        {
            if (intervals[i][1] < newInterval[0])
            {
                ans.push_back(intervals[i]);
            }
            else if (intervals[i][0] > newInterval[1])
            {
                break;
            }
            else
            {
                newInterval[0] = min(newInterval[0], intervals[i][0]);
                newInterval[1] = max(newInterval[1], intervals[i][1]);
            }
            i++;
        }
        ans.push_back(newInterval);
        while (i < n)
        {
            ans.push_back(intervals[i]);
            i++;
        }
        return ans;
    }
};
// T.C : O(n)
// S.C : O(n)