#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

/**
 * ------------------------------------ Introducion ------------------------------------
 * Title : Arithmetic Subarrays
 * LeetCode No : 1630
 * Diffulty : Medium
 * Topic : Array, Sorting, Hash Table
 * Link : https://leetcode.com/problems/arithmetic-subarrays/
 *
 */

/**
 * ------------------------------------ Problem Statement ------------------------------------
 * A sequence of numbers is called arithmetic if it consists of at least two elements,
 * and the difference between every two consecutive elements is the same.
 * More formally, a sequence s is arithmetic if and only if
 * s[i+1] - s[i] == s[1] - s[0] for all valid i.
 *
 * For example, these are arithmetic sequences:
 * 1, 3, 5, 7, 9
 * 7, 7, 7, 7
 * 3, -1, -5, -9
 * The following sequence is not arithmetic:
 * 1, 1, 2, 5, 7
 * You are given an array of n integers, nums, and two arrays of m integers each,
 * l and r, representing the m range queries, where the ith query is the range [l[i], r[i]].
 * All the arrays are 0-indexed.
 * Return a list of boolean elements answer,
 * where answer[i] is true if the subarray nums[l[i]], nums[l[i]+1], ... , nums[r[i]]
 * can be rearranged to form an arithmetic sequence, and false otherwise.
 *
 * Input: nums = [4,6,5,9,3,7], l = [0,0,2], r = [2,3,5]
 * Output: [true,false,true]
 *
 */

// ------------------------------------ Approach 1 ------------------------------------
class Solution
{
public:
    bool checkAP(vector<int> &nums)
    {

        int n = nums.size();
        int d = nums[1] - nums[0];

        for (int i = 2; i < n; i++)
        {
            if (nums[i] - nums[i - 1] != d)
                return false;
        }
        return true;
    }

    vector<bool> checkArithmeticSubarrays(vector<int> &nums, vector<int> &l, vector<int> &r)
    {

        int n = l.size();
        vector<bool> result(n);

        for (int i = 0; i < n; i++)
        {
            int start = l[i], end = r[i];

            vector<int> subArr(begin(nums) + start, begin(nums) + end + 1);
            sort(subArr.begin(), subArr.end());
            result[i] = checkAP(subArr);
        }
        return result;
    }
};
// Time Complexity : O(n * m * log(m))
// Space Complexity : O(m)

// ------------------------------------ Approach 2 ------------------------------------

class Solution
{
public:
    bool checkAP(vector<int> &nums)
    {

        int n = nums.size();

        // set to store all elements of AP
        unordered_set<int> set;
        int maxE = INT_MIN, minE = INT_MAX;

        // finding first and last term term of AP
        for (auto &element : nums)
        {
            maxE = max(maxE, element);
            minE = min(minE, element);
            set.insert(element);
        }
        // can common diffrence is possible
        if ((maxE - minE) % (n - 1) != 0)
            return false;

        // common difference
        int cd = (maxE - minE) / (n - 1);

        // checking if all terms are present in AP
        int curr = minE;
        while (curr < maxE)
        {
            if (set.find(curr) == set.end())
                return false;
            curr = curr + cd;
        }
        return true;
    }

    vector<bool> checkArithmeticSubarrays(vector<int> &nums, vector<int> &l, vector<int> &r)
    {

        int n = l.size();
        vector<bool> result(n);

        for (int i = 0; i < n; i++)
        {
            int start = l[i], end = r[i];

            vector<int> subArr(begin(nums) + start, begin(nums) + end + 1);
            result[i] = checkAP(subArr);
        }
        return result;
    }
};
// Time Complexity : O(n * m)
// Space Complexity : O(m)