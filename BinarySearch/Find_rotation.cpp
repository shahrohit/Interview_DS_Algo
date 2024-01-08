#include <vector>

using namespace std;

/**
 * ------------------------------------ Introducion ------------------------------------
 * Title : Find Rotation
 * platform : GFG
 * Difficulty : Easy
 * Topic : Binary Search
 * Link : https://practice.geeksforgeeks.org/problems/rotation4723/1
 *
 */

/**
 * ------------------------------------ Problem Statement ------------------------------------
 * Given an ascending sorted rotated array Arr of distinct integers of size N.
 * The array is right rotated K times.
 * Find the value of K.
 *
 * Example 1:
 * Input:
 * N = 5
 * Arr[] = {5, 1, 2, 3, 4}
 * Output: 1
 */

/**
 * ------------------------------------ Approach 1 ------------------------------------
 * Time Complexity : O(n)
 * Space Complexity : O(1)
 * Description : Linear Search
 */

class Solution
{
public:
    int findKRotation(vector<int> &arr)
    {
        int n = arr.size();
        int min = arr[0];
        int min_index = 0;

        for (int i = 0; i < n; i++)
        {
            if (min > arr[i])
            {
                min = arr[i];
                min_index = i;
            }
        }

        return min_index;
    }
};

/**
 * ------------------------------------ Approach 2 ------------------------------------
 * Time Complexity : O(logn)
 * Space Complexity : O(1)
 * Description : Binary Search
 */

class Solution
{
public:
    int findKRotation(int arr[], int n)
    {
        // code here
        int k = 0;
        int i = 0, j = n - 1;
        while (i < j)
        {
            int mid = i + (j - i) / 2;
            if (arr[mid] < arr[j])
            {
                j = mid;
            }
            else
            {
                i = mid + 1;
            }
        }
        return j;
    }
};