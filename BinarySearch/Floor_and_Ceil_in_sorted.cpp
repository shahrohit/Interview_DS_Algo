#include <vector>
using namespace std;

/**
 * ------------------------------------ Introducion ------------------------------------
 * Title : Floor and Ceil in Sorted Array
 * Difficulty : Easy
 * Topic : Array, Binary Search
 *
 */

/**
 * ------------------------------------ Problem Statement ------------------------------------
 * You’re given an sorted array arr of n integers and an integer x. Find the floor and ceiling of x in arr[0..n-1].
 * The floor of x is the largest element in the array which is smaller than or equal to x.
 * The ceiling of x is the smallest element in the array greater than or equal to x.
 *
 * if floor or ceil will be -1 if not found
 *
 * Input Format: n = 6, arr[] = {3, 4, 4, 7, 8, 10}, x= 5
 * Result: 4 7
 * Explanation: The floor of 5 in the array is 4, and the ceiling of 5 in the array is 7.
 */

// ------------------------------------ Approach 1 ------------------------------------
class Solution
{
public:
    int getFloor(vector<int> &arr, int target)
    {
        int low = 0, high = arr.size() - 1;
        int floor = -1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (arr[mid] <= target)
            {
                floor = mid;
                low = mid + 1;
            }
            else
                high = mid - 1;
        }
        return floor;
    }
    int getCeil(vector<int> &arr, int target)
    {
        int low = 0;
        int high = arr.size() - 1;
        int ceil = -1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (arr[mid] >= target)
            {
                ceil = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
    }
    pair<int, int> getFloorAndCeil(vector<int> &a, int n, int x)
    {
        int f = getFloor(a, x);
        int c = getCeil(a, x);

        return {f, c};
    }
};
// Time Complexity : O(log(n))
// Space Complexity : O(1)
