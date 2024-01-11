#include <limits.h>
using namespace std;

/**
 * ------------------------------------ Introducion ------------------------------------
 * Title : Palindromic Number
 * LeetCode No : 9
 * Difficulty : Easy
 * Topic : Maths
 * Link : https://leetcode.com/problems/palindrome-number/description/
 *
 */

/**
 * ------------------------------------ Problem Statement ------------------------------------
 * Given an integer x, return true if x is a palindrome, and false otherwise.
 * Input: x = 121
 * Output: true
 * Explanation: 121 reads as 121 from left to right and from right to left.
 *
 * Input: x = -121
 * Output: false
 * Explanation: From left to right, it reads -121. From right to left, it becomes 121-.
 * Therefore it is not a palindrome.
 */

// ------------------------------------ Approach 1 ------------------------------------
class Solution
{
public:
    bool isPalindrome(int x)
    {
        if (x < 0) // negative number are not palindrome
            return false;

        int temp = x;
        long long rev = 0;
        while (temp != 0)
        {
            int rem = temp % 10;
            rev = rev * 10 + rem;
            temp = temp / 10;
        }
        return rev == x;
    }
};

/**
 * -------------------------------- Approach - 2 ---------------------------------------------------
 * -> check the number is negative - negative numbers are not palindrome
 * -> Find the reverse of the number and store the reverse in varibale called 'rev'
 * -> Here, rev = rev * 10 + (num % 10) can be greater than INT_MAX which can give interger overflow
 * -> we can check rev * 10 > INT_MAX then return false
 * -> but since rev is in interger so rev * 10 giver interger overflow
 * -> we can check if(rev > INT_MAX / 10) return false;
 */
class Solution
{
public:
    bool isPalindrome(int x)
    {
        if (x < 0) // negative number are not palindrome
            return false;

        int temp = x;
        int rev = 0;
        while (temp != 0)
        {
            int rem = temp % 10;    // last digit
            if (rev > INT_MAX / 10) // interger overflow checking
                return false;

            rev = rev * 10 + rem; // if rev = 4 and rem = 2 => rev = 4 * 10 + 2 = 40 + 2 = 42
            temp = temp / 10;     // removing last element
        }
        return rev == x;
    }
};