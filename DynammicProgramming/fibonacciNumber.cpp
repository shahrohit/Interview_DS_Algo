#include <vector>
using namespace std;

// ----------------------- Introduction ------------------------------------------
// Title : Fibonacci Number
// LeetCode No : 509
// Difficulty : Easy
// Topics : Math, Dynammic Programming
// Link : https://leetcode.com/problems/fibonacci-number/description/

// ----------------------- Problem Statement -----------------------------------------------
// The Fibonacci numbers, commonly denoted F(n) form a sequence, called the Fibonacci sequence,
// such that each number is the sum of the two preceding ones, starting from 0 and 1. That is,

// F(0) = 0, F(1) = 1
// F(n) = F(n - 1) + F(n - 2), for n > 1.

// Input: n = 4
// Output: 3
// Explanation: F(4) = F(3) + F(2) = 2 + 1 = 3.

// ----------------------- Approach 1 : Recursive -------------------------------------------
class Solution
{
public:
    int fib(int n)
    {
        if (n <= 1)
            return n;
        //
        // F(2) = F(1) + F(0) : 0 1 1 2 3 5 8 21 ...
        // F(n) = F(n - 1) + F(n - 2)
        return fib(n - 1) + fib(n - 2);
    }
};
// T.C : O(2^n)
// S.C : O(1)

// ----------------------- Approach 2 : Top Down (Memoization) ------------------------------
class Solution
{
public:
    int solve(int n, vector<int> &dp)
    {
        if (n <= 1)
            return n;
        if (dp[n] != -1)
            return dp[n];

        return dp[n] = fib(n - 1) + fib(n - 2);
    }
    int fib(int n)
    {
        vector<int> dp(n + 1, -1);
        return solve(n, dp);
    }
};
// T.C : O(n)
// S.C : (n)

// ----------------------- Approach 3 : Bottom Up --------------------------------------------
class Solution
{
public:
    int fib(int n)
    {
        vector<int> dp(n + 1);
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};
// T.C : O(n)
// S.C : O(n)

// ----------------------- Approach 4 : Optimized --------------------------------------------
class Solution
{
public:
    int fib(int n)
    {
        // 0 1 1 2 3 5 8 13 21 ...
        int first = 0;
        int second = 1;

        for (int i = 1; i <= n; i++)
        {
            int next = first + second;
            first = second;
            second = next;
        }
        return first;
    }
};
// T.C : O(n)
// S.C : O(1)