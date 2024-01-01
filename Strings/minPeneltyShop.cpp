#include <string>
#include <algorithm>
using namespace std;

// ----------------------- Introduction ------------------------------------------
// Title : Minimum Penalty for a Shop
// LeetCode No : 2483
// Difficulty : Medium
// Topics : String
// Link : https://leetcode.com/problems/minimum-penalty-for-a-shop/description/

// ----------------------- Problem Statement --------------------------------------
// You are given the customer visit log of a shop represented by a 0-indexed string customers
// consisting only of characters 'N' and 'Y':

// the penalty is calculated as follows:
// For every hour when the shop is open and no customers come, the penalty increases by 1.
// For every hour when the shop is closed and customers come, the penalty increases by 1.
// Return the earliest hour at which the shop must be closed to incur a minimum penalty.

// Input: customers = "YYNY"
// Output: 2
// Explanation:
// - Closing the shop at the 0th hour incurs in 1+1+0+1 = 3 penalty.
// - Closing the shop at the 1st hour incurs in 0+1+0+1 = 2 penalty.
// - Closing the shop at the 2nd hour incurs in 0+0+0+1 = 1 penalty.
// - Closing the shop at the 3rd hour incurs in 0+0+1+1 = 2 penalty.
// - Closing the shop at the 4th hour incurs in 0+0+1+0 = 1 penalty.
// Closing the shop at 2nd or 4th hour gives a minimum penalty. Since 2 is earlier, the optimal closing time is 2.

// --------------------------- Approach 1   ----------------------------------------
class Solution
{
public:
    int bestClosingTime(string customers)
    {

        int penelty = count(begin(customers), end(customers), 'Y');
        int minPenelty = penelty;
        int minHrs = 0;

        for (int i = 0; i < customers.size(); i++)
        {
            if (customers[i] == 'Y')
                penelty--;
            else
                penelty++;

            if (minPenelty > penelty)
            {
                minPenelty = penelty;
                minHrs = i + 1;
            }
        }
        return minHrs;
    }
};
// TC : O(n)
// SC : O(1)