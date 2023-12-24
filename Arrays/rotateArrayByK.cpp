#include<vector>
#include<algorithm>
using namespace std;

// ----------------------- Introduction ------------------------------------------
// Title : Rotate Array 
// LeetCode No : 189
// Difficulty : Medium
// Topics : Array, Maths
// Link : https://leetcode.com/problems/rotate-array/description/


// ----------------------- Problem Statement --------------------------------------
// Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.
// Input: nums = [1,2,3,4,5,6,7], k = 3
// Output: [5,6,7,1,2,3,4]
// Explanation:
// rotate 1 steps to the right: [7,1,2,3,4,5,6]
// rotate 2 steps to the right: [6,7,1,2,3,4,5]
// rotate 3 steps to the right: [5,6,7,1,2,3,4]

// ----------------------- Approach 1 : Fill in Temporary Array  ---------------------------------
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;

        vector<int> tempArr(n);
        // store last k elements
        for(int i = 0; i < k; i++){
            tempArr[i] = nums[n - k + i];
        }
        // remaining elements
        for(int i = k; i < n; i++){
            tempArr[i] = nums[i-k];
        }

        nums = tempArr;
    }
};

// TC : O(n)
// SC : O(n)


// ------------------------ Approach 2 : Reverse method ------------------------------
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        
        k = k % nums.size();
        // reverse last k element
        reverse(nums.end() - k,nums.end());
        // reverse remaining elements
        reverse(nums.begin(),nums.end() - k);
        // reverse all elements
        reverse(nums.begin(),nums.end()); 
    }
};
// TC : O(n)
// SC : O(1)