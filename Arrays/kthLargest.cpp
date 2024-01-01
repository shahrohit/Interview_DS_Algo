#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

// ----------------------- Introduction ------------------------------------------
// Title : Non-overlapping Intervals
// LeetCode No : 435
// Difficulty : Medium
// Topics : Array, Greedy , Sorting
// Link : https://leetcode.com/problems/non-overlapping-intervals/description/

// ----------------------- Problem Statement --------------------------------------
// Given an integer array nums and an integer k, return the kth largest element in the array.
// Note that it is the kth largest element in the sorted order, not the kth distinct element.

// Input: nums = [3,2,1,5,6,4], k = 2
// Output: 5

// ---------------------------- Approach 1 : Sorting  ---------------------------------------
class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        sort(begin(nums), end(nums)); // ascending order
        return nums[nums.size() - k];

        // or,
        // sort(begin(nums), end(nums), greater<int>()); // descending order
        // return nums[k - 1];
    }
};

// ---------------------------- Approach 2 : Min Heap  ---------------------------------------
class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        // mean heap
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < k; i++)
        {
            pq.push(nums[i]);
        }

        for (int i = k; i < nums.size(); i++)
        {
            if (nums[i] > pq.top())
            {
                pq.pop();
                pq.push(nums[i]);
            }
        }

        return pq.top();
    }
};
// T.C : O(nlog(n))
// S.C : (1)

// ---------------------------- Approach 3 : Quick Select (Hoare's Partition ) ------------------
class Solution
{
public:
    int partition_algo(vector<int> &nums, int i, int j)
    {
        int p = i;
        i = i + 1;
        while (i <= j)
        {
            if (nums[i] < nums[p] && nums[j] > nums[p])
            {
                swap(nums[i++], nums[j--]);
            }
            if (nums[i] >= nums[p])
                i++;
            if (nums[j] <= nums[p])
                j--;
        }
        swap(nums[p], nums[j]);
        return j;
    }
    int findKthLargest(vector<int> &nums, int k)
    {

        int n = nums.size();
        int l = 0;
        int r = n - 1;
        int pivot_idx = 0;
        while (true)
        {
            pivot_idx = partition_algo(nums, l, r);
            if (pivot_idx == k - 1)
                break;
            else if (pivot_idx > k - 1)
                r = pivot_idx - 1;
            else
                l = pivot_idx + 1;
        }
        return nums[pivot_idx];
    }
};
// T.C : O(n * n), average T.C => O(n)
// S.C : (1)
