#include <vector>
#include <algorithm>
using namespace std;

// ----------------------- Introduction ------------------------------------------
// Title : Factorials of large numbers
// Platform : GFG
// Difficulty : Medium
// Topics : Maths, Array
// Link : https://practice.geeksforgeeks.org/problems/factorials-of-large-numbers2508/1

// ----------------------- Problem Statement --------------------------------------
// Given an integer N, find its factorial.
// return a list of integers denoting the digits that make up the factorial of N.
// Input: N = 5
// Output: 120
// Explanation : 5! = 1 * 2 * 3 * 4 * 5 = 120

// ------------------------ Approach 1 :  ------------------------------

class Solution
{
public:
    vector<int> factorial(int N)
    {

        vector<int> fact;
        fact.push_back(1);
        // initially fact will store the value in reverse order
        // Example : 5! = 120
        // fact => 0,2,1
        for (int i = 1; i <= N; i++)
        {
            int carry = 0;
            int size = fact.size();
            // multiping ever digit of prev fact with the i to get the current factorial
            // example: 4! = 24
            // but fact will store 4,2
            // multiply every digit with i = 5 (in this case) to get 5! in reverse order
            // fact = 0,2,1
            for (int j = 0; j < size; j++)
            {
                int val = fact[j] * i + carry;
                fact[j] = val % 10;
                carry = val / 10;
            }
            while (carry != 0)
            {
                fact.push_back(carry % 10);
                carry = carry / 10;
            }
        }
        // reverse the fact to get in corred order
        reverse(begin(fact), end(fact));
        return fact;
    }
};

// TC : O(n * k) where, k : no digits in n!
// SC : O(n)