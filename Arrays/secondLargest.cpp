#include <vector>
#include <algorithm>
using namespace std;

// ----------------------- Introduction ------------------------------------------
// Title : Second Largest
// Platform : GFG
// Difficulty : Easy
// Topics : Array, Searching
// Link : https://www.geeksforgeeks.org/problems/second-largest3735/1

// ----------------------- Problem Statement --------------------------------------

// Given an array Arr of size N, print second largest distinct element from an array.
// Arr[] = {12, 35, 1, 10, 34, 1}
// Output: 34
// Explanation: The largest element of the
// array is 35 and the second largest element is 34.

// ----------------------- Approach 1 : Sorting ---------------------------------
class Solution
{
public:
    int print2largest(vector<int> &arr)
    {
        int first = INT_MIN, second = INT_MIN;
        for (int &num : arr)
        {
            if (num > first)
            {
                second = first;
                first = num;
            }
            else if (num > second & num != first)
            {
                second = num;
            }
        }

        return second == INT_MIN ? -1 : second;
    }
};
// TC : O(n)
// SC : O(1)