#include <bits/stdc++.h>
using namespace std;
/**
 * ------------------------------------ Introducion ------------------------------------
 * Title : Maximum 69 Number
 * Leetcode No : 1323
 * Difficulty : Easy
 * Topic : Greedy, Math
 * Link : https://leetcode.com/problems/maximum-69-number/
 *
 */

/**
 * ------------------------------------ Problem Statement ------------------------------------
 * Given a positive integer num consisting only of digits 6 and 9.
 * Return the maximum number you can get by changing at most one digit (6 becomes 9, and 9 becomes 6).
 *
 * Example 1:
 * Input: num = 9669
 * Output: 9969
 */

// ------------------------------------ Approach 1 : String ------------------------------------
class Solution
{
public:
    int maximum69Number(int num)
    {
        string digits = to_string(num);
        for (char &digit : digits)
        {
            if (digit == '6')
            {
                digit = '9';
                break;
            }
        }
        return stoi(digits);
    }
};
// Time Complexity : O(n)
// Space Complexity : O(n)

// ------------------------------------ Approach 2 : Math ------------------------------------
class Solution
{
public:
    int maximum69Number(int num)
    {

        int temp = num;
        int digitPlace = 0;
        int placeValue = -1;

        while (temp != 0)
        {
            if (temp % 10 == 6)
                placeValue = digitPlace;

            temp = temp / 10;
            digitPlace++;
        }

        if (placeValue == -1)
            return num;

        return num + 3 * pow(10, placeValue);
    }
};