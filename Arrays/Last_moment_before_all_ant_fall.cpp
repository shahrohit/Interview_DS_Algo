#include <vector>
using namespace std;

/**
 * ------------------------------------ Introducion ------------------------------------
 * Title : Last Moment Before All Ants Fall Out of a Plank
 * LeetCode No : 1503
 * Diffulty : Medium
 * Topic : Array, Simulation
 * Link : https://leetcode.com/problems/last-moment-before-all-ants-fall-out-of-a-plank/
 *
 */

/**
 * ------------------------------------ Problem Statement ------------------------------------
 * We have a wooden plank of the length n units. Some ants are walking on the plank, each ant moves with speed 1 unit per second.
 * Some of the ants move to the left, the other move to the right.
 * When two ants moving in two different directions meet at some point, they change their directions and continue moving again.
 * Assume changing directions doesn't take any additional time.
 * When an ant reaches one end of the plank at a time t, it falls out of the plank imediately.
 *
 * Given an integer n and two integer arrays left and right, the positions of the ants moving to the left and the right.
 * Return the moment when the last ant(s) fall out of the plank.
 *
 * Example 1:
 * Input: n = 4, left = [4,3], right = [0,1]
 * Output: 4
 *
 */

// ------------------------------------ Approach 1 ------------------------------------

class Solution
{
public:
    int getLastMoment(int n, vector<int> &left, vector<int> &right)
    {

        int time = 0;
        for (auto &x : left)
        {
            time = max(time, x);
        }

        for (auto &x : right)
        {
            time = max(time, n - x);
        }

        return time;
    }
};
// Time Complexity : O(m + n), where m and n are the sizes of left and right respectively
// Space Complexity : O(1)