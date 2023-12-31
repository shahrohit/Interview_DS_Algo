#include <vector>
#include <string>
using namespace std;

// ----------------------- Introduction ------------------------------------------
// Title : Summary Ranges
// LeetCode No : 228
// Difficulty : Easy
// Topics : Medium
// Link : https://leetcode.com/problems/summary-ranges/description/

// ----------------------- Problem Statement --------------------------------------
// You are given a sorted unique integer array nums.
// A range [a,b] is the set of all integers from a to b (inclusive).
// Return the smallest sorted list of ranges that cover all the numbers in the array exactly.
// That is, each element of nums is covered by exactly one of the ranges, and there is no integer x
// such that x is in one of the ranges but not in nums.

// Each range [a,b] in the list should be output as:

// "a->b" if a != b
// "a" if a == b

// Input: nums = [0,1,2,4,5,7]
// Output: ["0->2","4->5","7"]
// Explanation: The ranges are:
// [0,2] --> "0->2"
// [4,5] --> "4->5"
// [7,7] --> "7"

// ----------------------- Approach 1  ---------------------------------
class Solution
{
public:
    vector<string> summaryRanges(vector<int> &nums)
    {

        int n = nums.size();

        vector<string> result;

        int start = 0, end = 0;
        for (int i = 0; i < n; i++)
        {
            //  nums[i + 1] - nums[i] == 1
            if (i + 1 < n && nums[i] + 1 == nums[i + 1])
                end = i + 1;
            else
            {
                string str = to_string(nums[start]);
                if (start != end)
                    str = str + "->" + to_string(nums[end]);

                result.push_back(str);
                start = end = i + 1;
            }
        }
        return result;
    }
};
// T.C : O(n)
// S.C : O(1)