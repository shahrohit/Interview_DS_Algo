#include <string>
using namespace std;

// ----------------------- Introduction ------------------------------------------
// Title : Minimum Changes To Make Alternating Binary String
// LeetCode No : 1758
// Difficulty : Easy
// Topics : String
// Link : https://leetcode.com/problems/minimum-changes-to-make-alternating-binary-string/description

// ----------------------- Problem Statement --------------------------------------
// You are given a string s consisting only of the characters '0' and '1'. In one operation, you can change any '0' to '1' or vice versa.
// The string is called alternating if no two adjacent characters are equal.

// Input: s = "0100"
// Output: 1
// Explanation: If you change the last character to '1', s will be "0101", which is alternating.

// ----------------------- Approach 1 : Start with Zero or Start with One ---------------------------------
// once we make alternate string, there is two possiblility
// 1. either it start with 0
// 2. or it start with 1
// If start with 0, then even idx characters will be 0 and Odd will be 1
// If start with 1, then even idx character will be 1 and even will be 0

class Solution
{
public:
    int minOperations(string s)
    {

        int n = s.size();

        int startWith0 = 0, startWith1 = 0;

        for (int i = 0; i < n; i++)
        {
            // for even index
            if (i % 2 == 0)
            {
                if (s[i] == '0')
                    startWith1++;
                else
                    startWith0++;
            }
            else
            {
                if (s[i] == '1')
                    startWith1++;
                else
                    startWith0++;
            }
        }

        return min(startWith0, startWith1);
    }
};
// T.C : O(n)
// S.C : O(1)

// ------------------------ Approach 2 : in one check  ------------------------------
class Solution
{
public:
    int minOperations(string s)
    {

        int n = s.size();

        int startWith0 = 0;

        for (int i = 0; i < n; i++)
        {
            // for even index
            if (i % 2 == 0)
            {
                if (s[i] == '1')
                    startWith0++;
            }
            else
            {
                if (s[i] == '0')
                    startWith0++;
            }
        }

        return min(startWith0, n - startWith0);
    }
};
// T.C : O(n)
// S.C : O(1)
