#include <vector>
#include <unordered_map>
using namespace std;

/**
 * ----------------------- Introduction ------------------------------------------
 * Title : Convert an Array Into a 2D Array With Conditions
 * Leetcode No : 2610
 * Difficulty : Medium
 * Topics : Array, Hash Table
 * Link : https://leetcode.com/problems/convert-an-array-into-a-2d-array-with-conditions/
 *
 */

/**
 * ----------------------- Problem Statement ------------------------------------------
 * You are given an interger array nums. You need to create a 2D array from nums satisfying the following conditions:
 * - The 2D array should contain only the elements of the array nums.
 * - Each row in the 2D array contains distinct integers.
 * - The number of rows in the 2D array should be minimal.
 *
 * Input: nums = [1,3,4,1,2,3,1]
 * Output: [[1,3,4,2],[1,3],[1]]
 * Explanation: We can create a 2D array that contains the following rows:
 * - 1,3,4,2
 *  - 1,3
 *  - 1
 * All elements of nums were used, and each row of the 2D array contains distinct integers, so it is a valid answer.
 * It can be shown that we cannot have less than 3 rows in a valid array.
 *
 */

// ----------------------- Approach 1 :  ---------------------------------

class Solution
{
public:
    vector<vector<int>> findMatrix(vector<int> &nums)
    {

        int maxFreq = 0;
        unordered_map<int, int> map;
        for (auto &element : nums)
        {
            map[element]++;
            maxFreq = max(maxFreq, map[element]);
        }
        vector<vector<int>> result(maxFreq);

        for (auto &[element, freq] : map)
        {

            for (int i = 0; i < freq; i++)
            {
                result[i].push_back(element);
            }
        }
        return result;
    }
};
