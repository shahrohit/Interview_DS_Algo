#include <bits/stdc++.h>
using namespace std;
/**
 * ------------------------------------ Introducion ------------------------------------
 * Title : Add Binary
 * Leetcode No : 67
 * Difficulty : Easy
 * Topic : String, Bit Manupulation
 * Link : https://leetcode.com/problems/add-binary/description/
 *
 */

/**
 * ------------------------------------ Problem Statement ------------------------------------
 * Given two binary strings a and b, return their sum as a binary string.
 * Input: a = "1010", b = "1011"
 * Output: "10101"
 */

/**
 * ------------------------------------ Approach 1 ------------------------------------
 * Time Complexity : O(n)
 * Space Complexity : O(n)
 */
class Solution
{
public:
    string addBinary(string a, string b)
    {
        int lenA = a.size(), lenB = b.size();
        int idxA = lenA - 1, idxB = lenB - 1;

        int carry = 0;
        string result = "";
        while (idxA >= 0 || idxB >= 0 || carry != 0)
        {
            int sum = carry;
            // string a is not complete
            if (idxA >= 0)
                sum += (a[idxA] - '0');

            // string b is not complete
            if (idxB >= 0)
                sum += (b[idxB] - '0');

            char digit = (sum & 1) + '0'; // digit = (sum % 2) + '0'
            carry = sum >> 1;             // carry  = sum / 2;
            result = digit + result;

            if (idxA >= 0)
                idxA--;

            if (idxB >= 0)
                idxB--;
        }
        return result;
    }
};