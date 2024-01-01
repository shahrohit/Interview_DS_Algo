#include <vector>
#include <unordered_map>
using namespace std;

// ----------------------- Introduction ------------------------------------------
// Title : Group the People Given the Group Size They Belong To
// LeetCode No : 1282
// Difficulty : Medium
// Topics : Array, HashTable
// Link : https://leetcode.com/problems/group-the-people-given-the-group-size-they-belong-to/description/

// ----------------------- Problem Statement --------------------------------------

// There are n people that are split into some unknown number of groups. Each person is labeled with a unique ID from 0 to n - 1.
// You are given an integer array groupSizes, where groupSizes[i] is the size of the group that person i is in.
// For example, if groupSizes[1] = 3, then person 1 must be in a group of size 3.
// Return a list of groups such that each person i is in a group of size groupSizes[i].
// Each person should appear in exactly one group, and every person must be in a group.
// If there are multiple answers, return any of them. It is guaranteed that there will be at least one valid solution for the given input.

// Input: groupSizes = [3,3,3,3,3,1,3]
// Output: [[5],[0,1,2],[3,4,6]]
// Explanation:
// The first group is [5]. The size is 1, and groupSizes[5] = 1.
// The second group is [0,1,2]. The size is 3, and groupSizes[0] = groupSizes[1] = groupSizes[2] = 3.
// The third group is [3,4,6]. The size is 3, and groupSizes[3] = groupSizes[4] = groupSizes[6] = 3.
// Other possible solutions are [[2,1,6],[5],[0,4,3]] and [[5],[0,6,2],[4,3,1]].

// -------------------------------------- Approach 1 --------------------------------------------------
class Solution
{
public:
    vector<vector<int>> groupThePeople(vector<int> &groupSizes)
    {
        unordered_map<int, vector<int>> map;
        vector<vector<int>> result;
        int n = groupSizes.size();
        for (int i = 0; i < n; i++)
        {
            int grp = groupSizes[i];
            map[grp].push_back(i);

            if (map[grp].size() == grp)
            {
                result.push_back(map[grp]);
                map.erase(grp);
            }
        }
        for (auto &[grp, vec] : map)
        {
            result.push_back(vec);
        }
        return result;
    }
};
// T.C : O(n)
// S.C : O(n)