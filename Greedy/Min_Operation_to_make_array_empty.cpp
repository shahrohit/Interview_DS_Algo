#include <vector>
#include <unordered_map>
#include <cmath>

using namespace std;

/**
 * ------------------------------------ Introducion ------------------------------------
 * Title : Minimum Number of Operations to Make Array Empty
 * LeetCode No : 2970
 * Diffulty : Medium
 * Topic : Array, Greedy, Hash Table
 * Link : https://leetcode.com/problems/minimum-number-of-operations-to-make-array-empty/
 *
 */

/**
 * ------------------------------------ Problem Statement ------------------------------------
 * You are given a 0-indexed array nums consisting of positive integers.
 * There are two types of operations that you can apply on the array any number of times:
 * - Choose two elements with equal values and delete them from the array.
 * - Choose three elements with equal values and delete them from the array.
 * Return the minimum number of operations required to make the array empty, or -1 if it is not possible.
 *
 * Input: nums = [2,3,3,2,2,4,2,3,4]
 * Output: 4
 */

// ------------------------------------ Approach 1 ------------------------------------
class Solution
{
public:
    int minOperations(vector<int> &nums)
    {
        unordered_map<int, int> map;
        for (int &element : nums)
        {
            map[element]++;
        }
        int count = 0;
        for (auto &[element, freq] : map)
        {
            if (freq == 1)
                return -1;

            count += ceil(freq / 3.0);
        }
        return count;
    }
};

// Time Complexity : O(n)
// Space Complexity : O(n)