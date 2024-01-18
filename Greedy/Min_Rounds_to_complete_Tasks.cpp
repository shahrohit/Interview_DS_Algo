#include <bits/stdc++.h>
using namespace std;
/**
 * ------------------------------------ Introducion ------------------------------------
 * Title : Minimum Rounds to Complete All Tasks
 * Leetcode No : 2244
 * Difficulty : Medium
 * Topic : Greedy, Hash Table
 * Link : https://leetcode.com/problems/minimum-rounds-to-complete-all-tasks/
 *
 */

/**
 * ------------------------------------ Problem Statement ------------------------------------
 * You are given a 0-indexed integer array tasks, where tasks[i] represents the difficulty level of a task.
 * In each round, you can complete either 2 or 3 tasks of the same difficulty level.
 * Return the minimum rounds required to complete all the tasks,
 * or -1 if it is not possible to complete all the tasks.
 *
 * Input: tasks = [2,2,3,3,2,4,4,4,4,4]
 * Output: 4
 */

// ------------------------------------ Approach 1 ------------------------------------
class Solution
{
public:
    int minimumRounds(vector<int> &tasks)
    {

        unordered_map<int, int> freqMap;
        for (auto &task : tasks)
        {
            freqMap[task]++;
        }

        int round = 0;
        for (auto &[task, freq] : freqMap)
        {
            if (freq == 1)
                return -1;

            round += ceil(freq / 3.0);
        }
        return round;
    }
};
// Time Complexity : O(n)
// Space Complexity : O(n)