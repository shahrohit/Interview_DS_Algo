#include <vector>
#include <algorithm>
using namespace std;

/**
 * ------------------------------------ Introducion ------------------------------------
 * Title : Floor and Ceil in Sorted Array
 * Platform : Coding Ninja
 * Difficulty : Easy
 * Topic : Array, Binary Search
 * Link : https://www.codingninjas.com/studio/problems/occurrence-of-x-in-a-sorted-array_630456
 */

/**
 * ------------------------------------ Problem Statement ------------------------------------
 * You are given a sorted array containing N integers and a number X,
 * you have to find the occurrences of X in the given array.
 * Input Format:   X = 3 , arr[] = {2, 2 , 3 , 3 , 3 , 3 , 4}
 * Result: 4
 * Explanation: 3 is occurring 4 times in the given array so it is our answer.
 */

// ------------------------------------ Approach 1 ------------------------------------
class Solution
{
public:
    int countOccurance(vector<int> &arr, int X)
    {
        auto left = lower_bound(arr.begin(), arr.end(), X);
        auto right = upper_bound(arr.begin(), arr.end(), X);

        return right - left;
    }
};
// Time Complexity : O(log(n))
// Space Complexity : O(1)
