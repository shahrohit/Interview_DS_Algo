#include <bits/stdc++.h>
using namespace std;
/**
 * ------------------------------------ Introducion ------------------------------------
 * Title : Maximum Ice Cream Bars
 * Leetcode No : 1833
 * Difficulty : Medium
 * Topic : Greedy, Sorting, Array
 * Link : https://leetcode.com/problems/maximum-ice-cream-bars/
 *
 */

/**
 * ------------------------------------ Problem Statement ------------------------------------
 * Return the maximum number of ice cream bars the boy can buy with coins coins.
 * Input: costs = [1,3,2,4,1], coins = 7
 * Output: 4
 * Explanation: The boy can buy ice cream bars at indices 0,1,2,4 for a total price of 1 + 3 + 2 + 1 = 7.
 */

// ------------------------------------ Approach 1 ------------------------------------
class Solution
{
public:
    int maxIceCream(vector<int> &costs, int coins)
    {

        sort(costs.begin(), costs.end());
        int iceCream = 0;
        for (int &cost : costs)
        {

            if (coins >= cost)
            {
                iceCream++;
                coins -= cost;
            }
            else
                break;
        }
        return iceCream;
    }
};
// Time Complexity : O()
// Space Complexity : O()