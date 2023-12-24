#include<vector>
#include<algorithm>
using namespace std;

// ----------------------- Introduction ------------------------------------------
// Title : Squares of a Sorted Array
// LeetCode No : 977
// Difficulty : Easy
// Topics : Array, Sorting, Two Pointers
// Link : https://leetcode.com/problems/squares-of-a-sorted-array/description/


// ----------------------- Problem Statement --------------------------------------
// Given an integer array nums sorted in non-decreasing order,
// return an array of the squares of each number sorted in non-decreasing order.
// Input: nums = [-4,-1,0,3,10]
// Output: [0,1,9,16,100]
// Explanation: After squaring, the array becomes [16,1,0,9,100].
// After sorting, it becomes [0,1,9,16,100].

// ----------------------- Approach 1 : Brute Force (Sorting) ---------------------------------
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> sqArr;
        // store all the square number - O(n)
        for(auto &element : nums){
            sqArr.push_back(element * element);
        }
        // sort the sqr numbers - O(log(n))
        sort(sqArr.begin(),sqArr.end());
        return sqArr;
    }
};
// TC : O(n*log(n))
// SC : O(n)


// ------------------------ Approach 2 : Optimal Approach (Two Pointer) ------------------------------
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();

        vector<int> sqArr(n);
        // left -> traverse array from left to right
        // right -> traverse array from right to left
        int left = 0, right = n - 1; 
        int sqIdx = n - 1; // fill sqArr from n-1 index to 0

        while(left <= right){ // -> O(n)

            if(abs(nums[left]) > abs(nums[right])){
                sqArr[sqIdx--] = nums[left] * nums[left];
                left++;
            }
            else{
                sqArr[sqIdx--] = nums[right] * nums[right];
                right--;
            }
        }
        return sqArr;
    }
};

// TC : O(n)
// SC : O(n)
