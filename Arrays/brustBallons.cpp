#include <vector>
#include <algorithm>
using namespace std;

// ----------------------- Introduction ------------------------------------------
// Title : Minimum Number of Arrows to Burst Balloons
// LeetCode No : 452
// Difficulty : Medium
// Topics : Array, Sorting
// Link : https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/description/

// ----------------------- Problem Statement --------------------------------------
// Given the array points, return the minimum number of arrows that must be shot to burst all balloons.
// Input: points = [[10,16],[2,8],[1,6],[7,12]]
// Output: 2

// ------------------------ Approach 2   ------------------------------
class Solution
{
public:
    int findMinArrowShots(vector<vector<int>> &points)
    {

        sort(begin(points), end(points));
        int n = points.size();

        int arrows = 1;
        int prevStart = points[0][0], prevEnd = points[0][1];

        for (int i = 1; i < n; i++)
        {
            int currStart = points[i][0];
            int currEnd = points[i][1];

            if (currStart <= prevEnd)
            {
                prevStart = currStart;
                prevEnd = min(prevEnd, currEnd);
            }
            else
            {
                arrows++;
                prevStart = currStart;
                prevEnd = currEnd;
            }
        }
        return arrows;
    }
};