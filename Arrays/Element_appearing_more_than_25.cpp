#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

/**
 * ----------------------- Introduction ------------------------------------------
 * Title : Element Appearing More Than 25% In Sorted Array
 * LeetCode No : 1287
 * Difficulty : Easy
 * Topics : Array, Binary Search
 * Link : https://leetcode.com/problems/element-appearing-more-than-25-in-sorted-array/
 */

/**
 * ----------------------- Problem Statement ------------------------------------------
 * Given an integer array sorted in non-decreasing order,
 * there is exactly one integer in the array that occurs more than 25% of the time.
 * Return that integer.
 *
 * Input: arr = [1,2,2,6,6,6,6,7,10]
 * Output: 6
 *
 */

// ----------------------- Approach 1 : Brute Force ---------------------------------
class Solution
{
public:
    int findSpecialInteger(vector<int> &arr)
    {
        int n = arr.size();
        unordered_map<int, int> map;
        int freq = n / 4;

        for (int &element : arr)
        {
            map[element]++;
            if (map[element] > freq)
                return element;
        }
        return -1;
    }
};
// TC : O(n)
// SC : O(n)

// ------------------------ Approach 2  ----------------------------
class Solution
{
public:
    int findSpecialInteger(vector<int> &arr)
    {
        int n = arr.size();
        int freq = n / 4;

        for (int i = 0; i < n - freq; i++)
        {
            if (arr[i] == arr[i + freq])
                return arr[i];
        }
        return -1;
    }
};
// TC : O(n)
// SC : O(1)

// ------------------------ Approach 3 : Optimal Approach (Binary Search) ------------------
class Solution
{
public:
    int findFirstOccurance(vector<int> &arr, int target)
    {
        int low = 0, high = arr.size() - 1;
        int idx = -1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (arr[mid] == target)
            {
                idx = mid;
                high = mid - 1;
            }
            else if (arr[mid] > target)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return idx;
    }
    int findSpecialInteger(vector<int> &arr)
    {
        int n = arr.size();
        int freq = n / 4;

        vector<int> candidates = {arr[n / 4], arr[n / 2], arr[(3 * n) / 4]};

        for (int &cand : candidates)
        {
            int leftIdx = findFirstOccurance(arr, cand);
            int rightIdx = leftIdx + freq;

            if (rightIdx < n && arr[rightIdx] == arr[leftIdx])
                return arr[leftIdx];
        }
        return -1;
    }
};

// TC : O(logn)
// SC : O(1)

// ------------------------ Approach 4 : Optimal Approach (STL) ------------------
class Solution
{
public:
    int findSpecialInteger(vector<int> &arr)
    {
        int n = arr.size();
        int freq = n / 4;

        vector<int> candidates = {arr[n / 4], arr[n / 2], arr[(3 * n) / 4]};

        for (int &cand : candidates)
        {
            int leftIdx = lower_bound(begin(arr), end(arr), cand) - begin(arr);
            int rightIdx = leftIdx + freq;

            if (rightIdx < n && arr[rightIdx] == arr[leftIdx])
                return arr[leftIdx];
        }
        return -1;
    }
};
// TC : O(logn)
// SC : O(1)
