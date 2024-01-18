#include <bits/stdc++.h>
using namespace std;
/**
 * ------------------------------------ Introducion ------------------------------------
 * Title : Minimum Time to Make Rope Colorful
 * Leetcode No : 1578
 * Difficulty : Medium
 * Topic : Greedy
 * Link : https://leetcode.com/problems/minimum-time-to-make-rope-colorful/description/
 *
 */

/**
 * ------------------------------------ Problem Statement ------------------------------------
 * Alice has n balloons arranged on a rope. You are given a 0-indexed string colors
 * where colors[i] is the color of the ith balloon.
 * Alice wants the rope to be colorful. She does not want two consecutive balloons to be of the same color
 * You are given a 0-indexed integer array neededTime where neededTime[i] is the time (in seconds)
 * that Bob needs to remove the ith balloon from the rope.
 *
 * Return the minimum time Bob needs to make the rope colorful.
 *
 * Example 1:
 * Input: colors = "abaac", neededTime = [1,2,3,4,5]
 * Output: 3
 * Explanation: In the above image, 'a' is blue, 'b' is red, and 'c' is green.
 * Bob can remove the blue balloon at index 2. This takes 3 seconds.
 * There are no longer two consecutive balloons of the same color. Total time = 3.
 */

// ------------------------------------ Approach 1 ------------------------------------
class Solution
{
public:
    int minCost(string colors, vector<int> &neededTime)
    {
        int n = colors.size();
        int prevIdx = 0;
        int time = 0;
        for (int i = 1; i < n; i++)
        {
            // current color is different from previous color
            if (colors[i] != colors[prevIdx])
            {
                prevIdx = i;
                continue;
            }

            // current color is same as previous color
            // if neededTime of previous color is greater than current color
            if (neededTime[i] >= neededTime[prevIdx])
            {
                time += neededTime[prevIdx];
                prevIdx = i;
            }
            else
            {
                time += neededTime[i];
            }
        }
        return time;
    }
};
// Time Complexity : O(n)
// Space Complexity : O(1)