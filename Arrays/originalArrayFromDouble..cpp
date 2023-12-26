#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

// ----------------------- Introduction ------------------------------------------
// Title : Find Original Array From Doubled Array
// LeetCode No : 2007
// Difficulty : Medium
// Topics : Array, Hash Table, Sorting
// Link : https://leetcode.com/problems/find-original-array-from-doubled-array/description/

// ----------------------- Problem Statement --------------------------------------
// An integer array original is transformed into a doubled array changed by appending twice the value of every element in original,
// and then randomly shuffling the resulting array.

// Given an array changed, return original if changed is a doubled array.
// If changed is not a doubled array, return an empty array. The elements in original may be returned in any order.

// Input: changed = [1,3,4,2,6,8]
// Output: [1,3,4]
// Explanation: One possible original array could be [1,3,4]:
// - Twice the value of 1 is 1 * 2 = 2.
// - Twice the value of 3 is 3 * 2 = 6.
// - Twice the value of 4 is 4 * 2 = 8.
// Other original arrays could be [4,3,1] or [3,1,4].

// ----------------------- Approach 1 ---------------------------------
// 1. sort the array
// 2. Traverse the array
// 3. if a element is not present in the map then push in the ans array and increase the freq of (twice value of num) by 1
// 4. if the number is present in map then decrese the freq and if freq becomes 0 then erase it from map
// 5. at last if the map is empty means all elemnents have the doubled valued so reutrn ans arr
// 6. else return empty array
// map represent the doubled value which cant be the part of origibal array
class Solution
{
public:
    vector<int> findOriginalArray(vector<int> &changed)
    {
        sort(begin(changed), end(changed));

        unordered_map<int, int> map;
        vector<int> ans;

        for (auto &num : changed)
        {
            if (map.find(num) != map.end())
            {
                map[num]--;
                if (map[num] == 0)
                    map.erase(num);
            }
            else
            {
                ans.push_back(num);
                map[num * 2]++;
            }
        }
        if (map.empty())
            return ans;
        return {};
    }
};
// T.C : O(nlog(n))
// S.C : O(n)