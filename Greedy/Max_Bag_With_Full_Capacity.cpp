#include <bits/stdc++.h>
using namespace std;
/**
 * ------------------------------------ Introducion ------------------------------------
 * Title : Maximum Bags With Full Capacity of Rocks
 * Leetcode No : 2279
 * Difficulty : Medium
 * Topic : Greedy, Sorting, Array
 * Link : https://leetcode.com/problems/maximum-bags-with-full-capacity-of-rocks/description/
 *
 */

/**
 * ------------------------------------ Problem Statement ------------------------------------
 * Return the maximum number of bags that could have full capacity after placing the additional rocks in some bags.
 * Input: capacity = [2,3,4,5], rocks = [1,2,4,4], additionalRocks = 2
 * Output: 3
 * Explanation:
 * Place 1 rock in bag 0 and 1 rock in bag 1.
 * The number of rocks in each bag are now [2,3,4,4].
 */

// ------------------------------------ Approach 1 ------------------------------------
class Solution
{
public:
    int maximumBags(vector<int> &capacity, vector<int> &rocks, int additionalRocks)
    {
        int n = capacity.size();
        vector<int> required(n);

        // additional rocks required in each bag
        for (int i = 0; i < n; i++)
        {
            required[i] = capacity[i] - rocks[i];
        }
        // sort the required rocks in ascending order
        sort(required.begin(), required.end());

        int fullBag = 0;
        for (auto &req : required)
        {
            // if there is additional rocks left, then add it to the bag
            if (additionalRocks >= req)
            {
                additionalRocks -= req;
                fullBag++;
            }
            else
                break;
        }
        return fullBag;
    }
};
// Time Complexity : O(nlogn)
// Space Complexity : O(n)