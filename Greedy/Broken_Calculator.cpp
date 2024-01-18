#include <bits/stdc++.h>
using namespace std;
/**
 * ------------------------------------ Introducion ------------------------------------
 * Title : Broken Calculator
 * Leetcode No : 991
 * Difficulty : Medium
 * Topic : Greedy
 * Link :  https://leetcode.com/problems/broken-calculator/
 *
 */

/**
 * ------------------------------------ Problem Statement ------------------------------------
 * On a broken calculator that has a number showing on its display, we can perform two operations:
 *
 * Double: Multiply the number on the display by 2, or;
 * Decrement: Subtract 1 from the number on the display.
 * Initially, the calculator is displaying the number startValue.
 *
 * Return the minimum number of operations needed to display the number target.
 *
 * Example 1:
 * Input: startValue = 2, target = 3
 * Output: 2
 */

// ------------------------------------ Approach 1 ------------------------------------
class Solution
{
public:
    int brokenCalc(int startValue, int target)
    {
        int steps = 0;
        // Greedy Approach - Start from target and go to startValue
        while (startValue != target)
        {
            // If startValue is greater than target, then we can only subtract
            if (startValue > target)
            {
                steps = steps + (startValue - target);
                break;
            }
            // If target is even, then divide by 2
            if (target % 2 == 0)
            {
                target = target / 2;
            }
            else // If target is odd, then add 1
            {
                target += 1;
            }
            steps++;
        }
        return steps;
    }
};
// Time Complexity : O(n)
// Space Complexity : O(1)